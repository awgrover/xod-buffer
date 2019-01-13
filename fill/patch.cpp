//-- void buffer1::fill(value)
struct State {
  // not used
  };

{{ GENERATED_CODE }}

void evaluate(Context ctx) {

  if ( !isInputDirty<input_value>(ctx) ) return;

  auto value = static_cast<char> (getValue<input_value>(ctx)); // char
  auto _object = getValue<input_buffer1>(ctx); // buffer1

  if (_object && _object->buffer) {
    memset( _object->buffer, value, _object->len );
    emitValue<output_done>(ctx, 1); // pulse
  }
  else {
    emitValue<output_ERR>(ctx, 1); // pulse: bad "buffer1" object or bad char*: "not allocated"
  }

  emitValue<output_buffer>(ctx, _object); // convenience
}
