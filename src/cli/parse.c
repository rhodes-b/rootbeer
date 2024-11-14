#include "cli_module.h"

int rb_cli_main(const int argc, const char *argv[]) {
	if (argc < 2) {
		rb_cli_print_help();
		return 1;
	}

	if (strcmp(argv[1], "store") == 0) {
		return rb_cli_store(argc - 1, argv + 1);
	}

	if (strcmp(argv[1], "compose") == 0) {
		return rb_cli_compose(argc - 1, argv + 1);
	}

	rb_cli_print_help();
	return 1;
}
