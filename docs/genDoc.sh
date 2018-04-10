#!/bin/bash
cd "${0%/*}" # Set Working Dir to always be the Dir of this Script
doxygen Doxfile
