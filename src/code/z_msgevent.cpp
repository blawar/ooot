#define INTERNAL_SRC_CODE_Z_MSGEVENT_C
#include "global.h"
#include "ultra64/sched.h"
#include "def/createmesgqueue.h"
#include "def/recvmesg.h"
#include "def/sched.h"
#include "def/z_msgevent.h"

void MsgEvent_SendNullTask(void)
{
	s32 pad[4];
	OSScTask task;
	OSMesgQueue queue;
	OSMesg msg;
	u32 pad2[1];

	task.next = NULL;
	task.flags = OS_SC_RCP_MASK;
	task.msgQ = &queue;
	task.msg = NULL;
	task.framebuffer = NULL;
	task.list.t.type = M_NULTASK;
	osCreateMesgQueue(task.msgQ, &msg, 1);
	// osSendMesg(&gSchedContext.cmdQ, &task, OS_MESG_BLOCK);
	Sched_SendEntryMsg(&gSchedContext);
	// osRecvMesg(&queue, NULL, OS_MESG_BLOCK);
}
