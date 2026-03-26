#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Usage: $0 <chapter_dir> <example_dir>"
    echo "Example: $0 chapter01 example_1_1"
    exit 1
fi

CHAPTER_DIR=$1
EXAMPLE_DIR=$2

DIR="$CHAPTER_DIR/$EXAMPLE_DIR"

if [ -d "$DIR" ]; then
    echo "Error: Directory '$DIR' already exists. Aborting to prevent overwriting."
    exit 1
fi

echo "Creating example in $DIR"

mkdir -p "$DIR/src" "$DIR/include"

# Create CMakeLists.txt
cat > "$DIR/CMakeLists.txt" << EOF
ci_make_app(
    APP_NAME    "$EXAMPLE_DIR"
    CINDER_PATH \${CINDER_PATH}
    SOURCES     \${CMAKE_CURRENT_SOURCE_DIR}/src/$EXAMPLE_DIR.cpp
    # INCLUDES    \${CMAKE_CURRENT_SOURCE_DIR}/include \${CMAKE_SOURCE_DIR}/include
    # RESOURCES   \${CMAKE_CURRENT_SOURCE_DIR}/resources
)
EOF

# Create basic Cinder app source file
cat > "$DIR/src/$EXAMPLE_DIR.cpp" << EOF
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class $EXAMPLE_DIR : public App
{
public:
	void setup() override;
	void update() override;
	void draw() override;
};

void $EXAMPLE_DIR::setup()
{
}

void $EXAMPLE_DIR::update()
{
}

void $EXAMPLE_DIR::draw()
{
	gl::clear(Color(0, 0, 0));
}

CINDER_APP($EXAMPLE_DIR, RendererGl)
EOF

if grep -q "add_subdirectory( $DIR )" CMakeLists.txt; then
    echo "Note: '$DIR' is already in the root CMakeLists.txt. Skipping duplicate append."
else
    echo "add_subdirectory( $DIR )" >> CMakeLists.txt
fi

echo "Example structure created successfully."
