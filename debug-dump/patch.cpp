
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    if ( !isInputDirty<input_trigger>(ctx) ) return;
    auto mark = getValue<input_mark>(ctx);
    auto _object = getValue<input_buffer1>(ctx);
    char * buf = _object->buffer;
    const size_t len = _object->len;
    const char * end = buf + len;

    // Number of rows is /16 + 1 if any remainder (ceil)
    size_t rows = len / 16;
    if (len % 16 ) rows +=1;

    DEBUG_SERIAL.print(F("Buffer1:"));DEBUG_SERIAL.print(transactionTime());DEBUG_SERIAL.print(F(": "));
    for (auto it = mark.iterate(); it; ++it)
      DEBUG_SERIAL.print((char)*it);
    DEBUG_SERIAL.print(F(" @ ")); DEBUG_SERIAL.print((long) buf);
    DEBUG_SERIAL.print(F(" [")); DEBUG_SERIAL.print(len); DEBUG_SERIAL.print(F("] rows "));DEBUG_SERIAL.print(rows);
    DEBUG_SERIAL.print(F("\n"));

    // rows of 16
    for (; buf < end; buf += 16) {
        DEBUG_SERIAL.print((long) buf);DEBUG_SERIAL.print(F(": "));

        // 16 hex
        for(char *rowp = buf; rowp < buf+16;rowp++) {
            if (rowp < end) {
                DEBUG_SERIAL.print((int)*buf,HEX);DEBUG_SERIAL.print(F(" "));
            }
            else {
                DEBUG_SERIAL.print(F("   "));
            }
        }
        DEBUG_SERIAL.print(F(" "));

        // 16 chars
        for(char *rowp = buf; rowp < buf+16 && rowp < end;rowp++) {
            char c = *buf;
            DEBUG_SERIAL.print(c > 32 && c <128 ? c : '.');DEBUG_SERIAL.print(F(" "));
        }
        DEBUG_SERIAL.print(F("\n"));
    }
}
