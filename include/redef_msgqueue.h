#undef osCreateMesgQueue

static void osCreateMesgQueue(OSMesgQueue* mq, OSMesg* msg, s32 count)
{
    mq->mtqueue = NULL;
    mq->fullqueue = NULL;
    mq->validCount = 0;
    mq->first = 0;
    mq->msgCount = count;
    mq->msg = msg;
}

#undef osSendMesg

static s32 osSendMesg(OSMesgQueue* mq, OSMesg mesg, s32 flag)
{
    register u32 index;

    while(mq->validCount >= mq->msgCount)
    {
        if(flag == OS_MESG_BLOCK)
        {
            int zyz = 0;
        }
        else
        {
            return -1;
        }
    }

    index = (mq->first + mq->validCount) % mq->msgCount;
    mq->msg[index] = mesg;
    mq->validCount++;

    if(mq->mtqueue->next != NULL)
    {
        //osStartThread(__osPopThread(&mq->mtqueue));
    }


    return 0;
}

#undef osRecvMesg

static s32 osRecvMesg(OSMesgQueue* mq, OSMesg* msg, s32 flag)
{
    while(mq->validCount == 0)
    {
        if(flag == OS_MESG_NOBLOCK)
        {
            return -1;
        }
        else
        {
            return -1; // TODO FIX HACK
        }
    }

    if(msg != NULL)
    {
        *msg = mq->msg[mq->first];
    }

    mq->first = (mq->first + 1) % mq->msgCount;
    mq->validCount--;

    if(mq->fullqueue->next != NULL)
    {
        //osStartThread(__osPopThread(&mq->fullqueue));
    }

    return 0;
}

