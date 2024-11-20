
#if EXAMPLE_PLUGIN_ENABLE
#define EXAMPLE_PLUGIN \
    X(bar, foo)        \
    X(baz, baz)
#else
#define EXAMPLE_PLUGIN

#endif /* EXAMPLE_PLUGIN_ENABLE */


int foo();

int baz();

