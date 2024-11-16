project(
  'notcurses',
  ['c','cpp'],
  version: '3.0.11',
  meson_version: '>=1.1.0',
  license: 'Apache License, Version 2.0',
  license_files: 'COPYRIGHT',
  default_options : ['c_std=c23','cpp_std=c++17']
)

#   description: 'Blingful UI for modern terminal emulators'
#   url: 'https://nick-black.com/dankwiki/index.php/notcurses'

# I don't know what it does
version_tweak = 0

# It needs to know version using defines
version_array = meson.project_version().split('.')
version_args = [
    '-D_MESON_NOTCURSES_VERNUM_MAJOR=@0@'.format(version_array[0]),
    '-D_MESON_NOTCURSES_VERNUM_MINOR=@0@'.format(version_array[1]),
    '-D_MESON_NOTCURSES_VERNUM_PATCH=@0@'.format(version_array[2]),
    '-D_MESON_NOTCURSES_VERNUM_TWEAK=@0@'.format(version_tweak)
    ]


notcurses_inc = include_directories('include','src')
ncpp_inc = include_directories('include')

curses_dep = dependency('curses', version: '>=6.1', required: true)


cc = meson.get_compiler('c')
# Locate libunistring manually
unistring_dep = cc.find_library('unistring', required: true)

subdir('src/lib')
subdir('src/libcpp')

# Patching use of deprecated feature
fix_ATOMIC_VAR_INIT = '-DATOMIC_VAR_INIT(_meson_patch_atomic_var)=_meson_patch_atomic_var' 

lib_notcurses = library(
  'notcurses',
  c_sources,
  include_directories: [notcurses_inc],
  dependencies: [curses_dep,unistring_dep],
  c_args: ['-D_GNU_SOURCE']+version_args+fix_ATOMIC_VAR_INIT,
  install: true
)

lib_ncpp = library(
  'notcurses++',
  cpp_sources,
  include_directories: [ncpp_inc, notcurses_inc],
  link_with: lib_notcurses,
  install: true
)

notcurses_headers = files(
    'include/notcurses/direct.h',
    'include/notcurses/nckeys.h',
    'include/notcurses/ncport.h',
    'include/notcurses/ncseqs.h',
    'include/notcurses/notcurses.h'
)

install_headers(notcurses_headers, subdir: 'notcurses')

ncpp_headers = files(
    'include/ncpp/_exceptions.hh',
    'include/ncpp/_flag_enum_operator_helpers.hh',
    'include/ncpp/_helpers.hh',
    'include/ncpp/Cell.hh',
    'include/ncpp/CellStyle.hh',
    'include/ncpp/Direct.hh',
    'include/ncpp/FDPlane.hh',
    'include/ncpp/Menu.hh',
    'include/ncpp/MultiSelector.hh',
    'include/ncpp/NCAlign.hh',
    'include/ncpp/NCBox.hh',
    'include/ncpp/NCKey.hh',
    'include/ncpp/NCLogLevel.hh',
    'include/ncpp/ncpp.hh',
    'include/ncpp/NotCurses.hh',
    'include/ncpp/Palette.hh',
    'include/ncpp/Pile.hh',
    'include/ncpp/Plane.hh',
    'include/ncpp/Plot.hh',
    'include/ncpp/Progbar.hh',
    'include/ncpp/Reader.hh',
    'include/ncpp/Reel.hh',
    'include/ncpp/Root.hh',
    'include/ncpp/Selector.hh',
    'include/ncpp/Subproc.hh',
    'include/ncpp/Tablet.hh',
    'include/ncpp/TabletCallback.hh',
    'include/ncpp/Utilities.hh',
    'include/ncpp/Visual.hh',
    'include/ncpp/Widget.hh'
)

install_headers(ncpp_headers, subdir: 'ncpp')
install_headers('include/ncpp/internal/Helpers.hh',subdir: 'ncpp/internal')
