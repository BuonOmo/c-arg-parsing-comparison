
#include <ruby.h>

#define ACTUAL_METHOD \
return rb_sprintf( \
"envelope: %" PRIsVALUE "\npolygons: %" PRIsVALUE "\ntolerance: %" PRIsVALUE "\nonly_edges: %" PRIsVALUE "\n", \
envelope, polygons, tolerance, only_edges \
);

VALUE c_voronoi_diagram(int argc, VALUE *argv, VALUE self) {
  VALUE envelope;
  VALUE polygons;
  VALUE tolerance;
  VALUE only_edges;

  VALUE kwargs;
  rb_scan_args(argc, argv, "1*:", &envelope, &polygons, &kwargs);

  ID table[2];
	table[0] = rb_intern("tolerance");
	table[1] = rb_intern("only_edges");
  VALUE values[2];
  rb_get_kwargs(kwargs, table, 1, 1, values);

  tolerance = values[0];
  only_edges = values[1] == Qundef ? Qfalse : values[1];

  ACTUAL_METHOD
}

VALUE primary_voronoi_diagram(VALUE self, VALUE envelope,
                              VALUE polygons, VALUE tolerance,
                              VALUE only_edges) {
  ACTUAL_METHOD
}

void Init_geo() {
  VALUE geo_mod = rb_define_module("Geo");
  VALUE primary_mod = rb_define_module_under(geo_mod, "Hidden");
  rb_define_singleton_method(geo_mod, "c_voronoi_diagram", c_voronoi_diagram, -1);
  rb_define_singleton_method(primary_mod, "voronoi_diagram", primary_voronoi_diagram, 4);
}
