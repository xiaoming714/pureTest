def _impl(ctx):
    print(dir(ctx))
    print("Target {}: attr number {}".format(ctx.label, ctx.attr.number))

hello = rule(
    implementation = _impl,
    attrs = {
        "number": attr.int(default = 1),
    },
)

def _impl_with_label(ctx):
    print(ctx.attr.mylabel)

hello_with_label = rule(
    implementation = _impl_with_label,
    attrs = {
        "mylabel": attr.label(),
    },
)
