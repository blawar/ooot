#pragma once
#ifdef INTERNAL_SRC_CODE_DB_CAMERA_C
void DbCamera_Init(DbCamera* dbCamera, Camera* cameraPtr);
void DbCamera_Reset(Camera* cam, DbCamera* dbCam);
void DbCamera_Update(DbCamera* dbCamera, Camera* cam);
void DbgCamera_Enable(DbCamera* dbCamera, Camera* cam);
#else
void DbCamera_Init(struct DbCamera* dbCamera, struct Camera* cameraPtr);
void DbCamera_Reset(struct Camera* cam, struct DbCamera* dbCam);
void DbCamera_Update(struct DbCamera* dbCamera, struct Camera* cam);
void DbgCamera_Enable(struct DbCamera* dbCamera, struct Camera* cam);
#endif
