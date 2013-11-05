import sys

mode = ARGUMENTS['mode']
variant_dir = 'build/debug' if mode == 'Debug' else 'build/release'

system = ''

if sys.platform.startswith('win32'):
    sconscript = 'win32-sconscript'
elif sys.platform.startswith('linux'):
    sconscript = 'linux-sconscript'
else:
    raise Exception("not supported system")

SConscript(
    dirs='.',
    name=sconscript,
    variant_dir=variant_dir,
    duplicate=0,
    exports="mode")