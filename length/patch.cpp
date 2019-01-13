//-- int buffer1::length()
// Our constructor namespace should be: buffer1_ll__buffer1
struct State {
  // not used
  };

{{ GENERATED_CODE }}

void evaluate(Context ctx) {

  if ( !isInputDirty<input_buffer1>(ctx) ) return;

  auto _object = getValue<input_buffer1>(ctx); // buffer1
  auto _rez = _object->len; // size_t in real life. Report 0 if actually 0

  emitValue<output_buffer>(ctx, _object); // convenience
  emitValue<output_val>(ctx, _rez); // int

}
