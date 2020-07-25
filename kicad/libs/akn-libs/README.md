# My kicad schmatic symbol libraries

Bunch of schematic symbols (usually for cheap weird parts). Most of the symbols can be
associated to footprints found in the kicad installation or one of the `.pretty` repositories
alongside (with the same basename).

## List of parts

### akn_misc.lib:

* DIODE_BRIDGE : Made it since the default kicad one was *huge*.
* PUSH_BUTTON_NO : Normally Open, push button.
* RJ11_PTH_STAGGER : RJ11 4C symbol. Defaults were huge.
* RJ12_PTH_STAGGER : RJ12 6C + 2 symbol. Defaults were huge.
* DISP_LED_MAT_8x8_COM_ANODE: 8x8 LED Display module, Common anode.
* DISP_LED_MAT_8x8_COM_CAT: 8x8 LED Display module, Common cathode.

### akn_transformers.lib

* TRANSFO-AUDIO : Small no-name audio transformer.

### akn_weird_ics.lib

* HT9032D : 8 pin Belcore FSK caller id decoder

## Typical usage with libs and footprints as git submodules

Setup your Kicad project at say, `projectdir`. If it is a git repository already
add these as submodules:

    cd projectdir
    git submodule add git@github.com:aniline/akn-kicad-libs.git libs/akn-libs

If you want an associated footprint library add them as submodule as well:

    git submodule add git@github.com:aniline/akn_misc.pretty.git modules/akn_misc.pretty

The 3D shapes library should be relative to the system-wide kicad 3d shapes directory. You
could put it somewhere outside the `projectdir` if you want to use it with other projects.
A sequence of steps like the following should work:

    cd /opt/my_kicad_shapes
    git clone https://github.com/aniline/akn.3dshapes.git
    su 
    cd /usr/share/kicad/modules/packages3d
    ln -s /opt/my_kicad_shapes/akn.3dshapes

The directory `/usr/share/kicad/modules/packages3d` is a typical 3d shapes top directory
on a linux kicad installation. On platforms where you cannot make symbolic links, copy the
clone to that directory (or clone it there). Also, the directory named `/opt/my_kicad_shapes`
is just for illustration.
