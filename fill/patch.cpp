//-- void buffer1::fill(value)
struct State {
  // not used
  };

{{ GENERATED_CODE }}

void evaluate(Context ctx) {

  if ( !isInputDirty<input_value>(ctx) ) return;

  auto value = static_cast<char> (getValue<input_value>(ctx)); // char
  auto _object = getValue<input_buffer1>(ctx); // buffer1

  memset( _object->buffer, value, _object->len );
  
  emitValue<output_buffer>(ctx, _object); // convenience

  emitValue<output_done>(ctx, 1); // pulse
}
