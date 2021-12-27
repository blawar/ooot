#pragma once

#define GIT_BRANCH "master"
#define GIT_TAG "nightly-build-dirty"
#define GIT_COMMIT_HASH "6660e93"
#define GIT_COMMIT_DATE "2022-01-10"

#define CORE_BASE_NAME "angrylion's RDP Plus"

#ifdef _DEBUG
#define CORE_NAME CORE_BASE_NAME " " GIT_TAG " (Debug)"
#else
#define CORE_NAME CORE_BASE_NAME " " GIT_TAG
#endif

#define CORE_SIMPLE_NAME "angrylion-plus"
