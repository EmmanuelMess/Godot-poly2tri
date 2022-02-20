#include "gdexample.h"

#include <vector>
#include <poly2tri.h>

using namespace godot;

void GDExample::_register_methods() {
    register_method("_process", &GDExample::_process);
}

GDExample::GDExample() {
}

GDExample::~GDExample() {
    // add your cleanup here
}

void GDExample::_init() {
    // initialize any variables here
    time_passed = 0.0;
}

void GDExample::_process(float delta) {
    time_passed += delta;

    Vector2 new_position = Vector2(10.0 + (10.0 * sin(time_passed * 2.0)), 10.0 + (10.0 * cos(time_passed * 1.5)));

    set_position(new_position);

    std::vector<p2t::Point*> polyline{ new p2t::Point(0, 0), new p2t::Point(0, 1),
                                     new p2t::Point(1, 1), new p2t::Point(1, 0) };
    p2t::CDT cdt{ polyline };
    const auto result = cdt.GetTriangles();
    p2t::IsDelaunay(result);

}

