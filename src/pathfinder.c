#include "pathfinder.h"

int main(int argc, char* argv[]) {
    check_err(argc, argv);
    t_graph *graph = read_file(argv[1]);
    print_routes(graph);
    clear_graph(graph);
}


