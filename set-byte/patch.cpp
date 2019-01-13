//-- void buffer1::set_byte(value, i)
// Our constructor namespace should be: buffer1_ll__buffer1
struct State {
  // not used
  };

{{ GENERATED_CODE }}

void evaluate(Context ctx) {

  // only act on trigger, inputs not relevant for this
  if ( !isInputDirty<input_trigger>(ctx) ) return;

  char value = getValue<input_value>(ctx); // char
  uint16_t i = static_cast<uint16_t> (getValue<input_i>(ctx));
  auto _object = getValue<input_buffer1>(ctx); // buffer1

    //DEBUG_SERIAL.print(F("set @")); DEBUG_SERIAL.print((long) _object->buffer);DEBUG_SERIAL.print(F("/"));DEBUG_SERIAL.print(_object->len);
    //DEBUG_SERIAL.print(F("["));DEBUG_SERIAL.print((int)i);DEBUG_SERIAL.print(F("]="));DEBUG_SERIAL.print((int)value,HEX);
    //DEBUG_SERIAL.print(F("\n"));
  if ( i < 0 || i  >= _object->len ) {
    emitValue<output_ERR>(ctx, 1); // pulse
  }
  else {
    _object->buffer[i] = value;
    emitValue<output_done>(ctx, 1); // pulse
  }
  emitValue<output_buffer>(ctx, _object); // convenience
}
