#ifndef SLANG_STD_WRITERS_H
#define SLANG_STD_WRITERS_H

#include "slang-writer.h"
#include "../../slang-com-ptr.h"

namespace Slang
{

/* Holds standard writers for the channels */
class StdWriters: public RefObject
{
public:

    ISlangWriter * getWriter(SlangWriterChannel chan) const { return m_writers[chan]; }
    void setWriter(SlangWriterChannel chan, ISlangWriter* writer) { m_writers[chan] = writer; }

        /// Set the writers on the SlangCompileRequest
    void setRequestWriters(SlangCompileRequest* request);

        /// Ctor
    StdWriters() {}

        /// Initialize a default context
    static RefPtr<StdWriters> createDefault();
    static RefPtr<StdWriters> initDefaultSingleton();

    static StdWriters* getSingleton() { return s_singleton; }
    static void setSingleton(StdWriters* context) { s_singleton = context;  }

    static WriterHelper getError() { return getSingleton()->getWriter(SLANG_WRITER_CHANNEL_STD_ERROR); }
    static WriterHelper getOut() { return getSingleton()->getWriter(SLANG_WRITER_CHANNEL_STD_OUTPUT); }
    static WriterHelper getDiagnostic() { return getSingleton()->getWriter(SLANG_WRITER_CHANNEL_DIAGNOSTIC); }

protected:

    ComPtr<ISlangWriter> m_writers[SLANG_WRITER_CHANNEL_COUNT_OF]; 
    
    static StdWriters* s_singleton;
};

}

#endif
