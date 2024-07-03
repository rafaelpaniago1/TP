#include "edge.hpp"

Edge::Edge(int to, double weight, bool is_portal) : to(to), weight(weight), is_portal(is_portal), next(nullptr) {}