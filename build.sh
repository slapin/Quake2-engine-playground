#!/bin/sh
ARCH=i386
rm -Rf testdir
make $*
mkdir testdir
mkdir testdir/baseq2
cp debug${ARCH}/quake2 testdir
cp debug${ARCH}/ref_*.so testdir
cp debug${ARCH}/game${ARCH}.so testdir/baseq2
ln -s ~/quake2/baseq2/pak0.pak testdir/baseq2/