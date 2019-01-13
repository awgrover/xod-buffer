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
  //DEBUG_SERIAL.print(F("buf "));DEBUG_SERIAL.print(bytes);

  if (bytes == 0) {
    _state->buffer = NULL;
    DEBUG_SERIAL.print(F("buffer1/buffer1 tried to allocate 0 bytes\n")); // exception
    }
  else {
    _state->buffer = malloc( bytes ); // try
    }
  //DEBUG_SERIAL.print(F(" @ "));DEBUG_SERIAL.print((long) _state->buffer);
  //DEBUG_SERIAL.print(F("\n"));

  if (_state->buffer) {
    // worked
    _state->len = bytes;
    emitValue<output_done>(ctx, 1); // fix type
    }
  else {
    _state->len = 0; // to be nice, ->buffer is already NULL
    emitValue<output_ERR>(ctx, 1);
    }
  emitValue<output_buffer1>(ctx, _state); // must emit, otherwise you get a default value (usually NULL)
}
