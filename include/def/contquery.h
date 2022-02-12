#pragma once
struct OSContStatus;
struct OSMesgQueue;

void osContGetQuery(OSContStatus* data);
s32 osContStartQuery(OSMesgQueue* mq);
