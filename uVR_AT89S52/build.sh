#!/bin/bash

source "config/build.conf"

TIMEF=$(date +%H.%M.%S)

option="$1"


case "$option" in
	"debug"|"DEBUG") 
		echo "Building Binaries uVR_AT89S52 $VERSION : "
		
		mkdir -p "${DEBUG}${VERSION}${TIMEF}"/
		
		sdcc -mmcs51 \-I "$INCLUDE" \-o "$DEBUG$VERSION${TIMEF}/" "$SRC"main.c
		
		packihx $DEBUG$VERSION$TIMEF/main.ihx > "${DEBUG}${VERSION}${TIMEF}/uvr_debug.hex"

		echo "Output File Generated : ${DEBUG}${VERSION}${TIMEF}/uvr_debug.hex"

		;;
	"buildsave"|"BUILDSAVE") 
		echo "Building Binaries uVR_AT89S52 $VERSION : "
		
		mkdir -p "${BUILD}${VERSION}${TIMEF}"/
		
		sdcc -mmcs51 \-I "$INCLUDE" \-o "${BUILD}${VERSION}${TIMEF}/" "$SRC"main.c
		
		packihx ${BUILD}${VERSION}${TIMEF}/main.ihx > "${BUILD}${VERSION}${TIMEF}/uvr_build.hex"

		echo "Output File Generated : ${BUILD}${VERSION}${TIMEF}/uvr_build.hex"

		;;
	
	"release"|"RELEASE")
		echo "Building Release uVR_AT89S52 $VERSION : "
		
		mkdir -p "${RELEASE}${VERSION}"/
		
		sdcc -mmcs51 \-I "$INCLUDE" \-o "${RELEASE}${VERSION}/" "$SRC"main.c
		
		packihx ${RELEASE}${VERSION}/main.ihx > "${RELEASE}${VERSION}/uvr_binary_release.hex"
		
		echo "Output File Generated : ${RELEASE}${VERSION}/uvr_binary_release.hex"
		
		;;
	
	*)
		echo "Invalid Selection!"
		echo "usage debug : Build Debug Binary , buildsave : Build Project"
		;;
esac

 
