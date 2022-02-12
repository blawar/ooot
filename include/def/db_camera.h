#pragma once
struct DbCamera;
struct Camera;

void DbCamera_Init(DbCamera* dbCamera, Camera* cameraPtr);
void DbCamera_Reset(Camera* cam, DbCamera* dbCam);
void DbCamera_Update(DbCamera* dbCamera, Camera* cam);
void DbgCamera_Enable(DbCamera* dbCamera, Camera* cam);
