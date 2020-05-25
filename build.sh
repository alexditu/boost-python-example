#!/bin/bash

function usage {
	echo "Usage: $0 [options...]"
	echo "-h	show this help"
	echo "-d	build directory, default './builddir'"
	echo "-d	install directory, default './installddir'"
	exit 1
}

BUILD_DIR="builddir"
INSTALL_DIR="installdir"

while getopts ":hb:d:" opt; do
	case ${opt} in
		h)
			usage
		;;
		b)
			BUILD_DIR="${opt}"
		;;
		d)
			INSTALL_DIR="${opt}"
		;;
		\?)
			echo "unkown option: ${opt}"
			usage
		;;
	esac
done

echo "Using build directory: ${BUILD_DIR}"
echo "Using install directory: ${BUILD_DIR}"

rm -rf "${BUILD_DIR}"
mkdir "${BUILD_DIR}"

cd "${BUILD_DIR}" || echo "failed to enter directory: ${BUILD_DIR}"
cmake -D INSTALL_DIR="${INSTALL_DIR}" ..

make install

echo "--------------- build done ---------------"
echo "please find the installed binaries in folder: ${INSTALL_DIR}"
