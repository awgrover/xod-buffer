//-- char buffer1::get_byte(i)
// Our constructor namespace should be: buffer1_ll__buffer1
struct State {
  // not used
  };

{{ GENERATED_CODE }}

void evaluate(Context ctx) {

  if ( !isInputDirty<input_trigger>(ctx) ) return;

  uint16_t i = static_cast<uint16_t> (getValue<input_i>(ctx));
  auto _object = getValue<input_buffer1>(ctx); // buffer1

  if ( ! _object->buffer ) {
    DEBUG_SERIAL.print(F("buffer1/"));DEBUG_SERIAL.print(F("get-byte")); DEBUG_SERIAL.print(F(" saw unallocated buffer1\n")); // exception
  }
  else if ( i < 0 || i  >= _object->len ) {
    emitValue<output_ERR>(ctx, 1); // pulse
  }
  else {
    uint8_t _rez = _object->buffer[ i ];
    //DEBUG_SERIAL.print(F("@")); DEBUG_SERIAL.print((long) _object->buffer);
    //DEBUG_SERIAL.print(F("[")); DEBUG_SERIAL.print(_rez,HEX); DEBUG_SERIAL.print(F("]\n"));
    emitValue<output_val>(ctx, _rez); // byte
    emitValue<output_done>(ctx, 1);
  }
  emitValue<output_buffer>(ctx, _object); // convenience
}
