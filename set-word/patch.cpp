//-- void buffer1::set_word(value, i)
// Our constructor namespace should be: buffer1_ll__buffer1
struct State {
  // not used
  };

{{ GENERATED_CODE }}

void evaluate(Context ctx) {

  // only act on trigger, inputs not relevant for this
  if ( !isInputDirty<input_trigger>(ctx) ) return;

  uint16_t value = static_cast<uint16_t> (getValue<input_value>(ctx)); // char
  uint16_t i = static_cast<uint16_t> (getValue<input_i>(ctx)); // int
  auto _object = getValue<input_buffer1>(ctx); // buffer1

  if ( ! _object->buffer ) {
    DEBUG_SERIAL.print(F("buffer1/"));DEBUG_SERIAL.print(F("set-word")); DEBUG_SERIAL.print(F(" saw unallocated buffer1\n")); // exception
  }
  else if ( i < 0 || (sizeof(uint16_t) * i) + 1  >= _object->len ) { // 2nd byte fits too?
    emitValue<output_ERR>(ctx, 1); // pulse
  }
  else {
    reinterpret_cast <uint16_t *> (_object->buffer)[i] = value;
    emitValue<output_done>(ctx, 1); // pulse
  }
  emitValue<output_buffer>(ctx, _object); // convenience
}
