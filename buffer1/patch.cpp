//-- constructor buffer1

// Our namespace should be: buffer1_ll__buffer1
struct State {
    size_t len; // larger than XOD can deal with
    byte *buffer;
  };
using Type = State*; // 'Type' is assumed by xod code-generator

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
  if (!isSettingUp()) return;
  auto _state = getState(ctx);
  uint16_t bytes = static_cast<uint16_t> (getValue<input_bytes>(ctx)); // casting gives us 16 bits
    DEBUG_SERIAL.print(F("buf "));DEBUG_SERIAL.print(bytes);
  _state->buffer = malloc( bytes ); // try
    DEBUG_SERIAL.print(F(" @ "));DEBUG_SERIAL.print((long) _state->buffer);
  if (_state->buffer) {
    // worked
    _state->len = bytes;
    emitValue<output_buffer1>(ctx, _state);
    emitValue<output_done>(ctx, 1); // fix type
    }
  else {
    emitValue<output_ERR>(ctx, 1);
    }
    DEBUG_SERIAL.print(F("\n"));
}
