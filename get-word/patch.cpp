//-- int buffer1::get_word(i)
// Our constructor namespace should be: buffer1_ll__buffer1
struct State {
  // not used
  };

{{ GENERATED_CODE }}

void evaluate(Context ctx) {

  if ( !isInputDirty<input_i>(ctx) ) return;

  uint16_t i = static_cast<uint16_t> (getValue<input_i>(ctx));
  auto _object = getValue<input_buffer1>(ctx); // buffer1

  if ( ! _object->buffer ) {
    DEBUG_SERIAL.print(F("buffer1/"));DEBUG_SERIAL.print(F("get-word")); DEBUG_SERIAL.print(F(" saw unallocated buffer1\n")); // exception
  }
  else if ( i < 0 || (i * sizeof(uint16_t) >= _object->len) ) {
    emitValue<output_ERR>(ctx, 1); // pulse
  }
  else {
    auto _rez = reinterpret_cast <uint16_t *> ( _object->buffer )[ i ]; // int

    emitValue<output_val>(ctx, _rez); // int
  }
  emitValue<output_buffer>(ctx, _object); // convenience
}
