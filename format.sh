#!/usr/bin/env bash
find src/ iname '*.cpp' -exec clang-format -i -style=file "{}" \;
find src/ iname '*.h' -exec clang-format -i -style=file "{}" \;
find include/ iname '*.h' -exec clang-format -i -style=file "{}" \;
