#ifndef EVENT_H
#define EVENT_H

#include "BaseFiller.h"
#include "PandaProd/Objects/interface/PEvent.h"

#include <map>
#include <string>

namespace panda {
class EventFiller : virtual public BaseFiller
{
    public:
        EventFiller(TString n);
        ~EventFiller();
        int analyze(const edm::Event& iEvent);
        virtual inline string name(){return "EventFiller";};
        void init(TTree *t);

        edm::EDGetTokenT<GenEventInfoProduct> gen_token;
        edm::Handle<GenEventInfoProduct> gen_handle;
        
        edm::Handle<reco::VertexCollection> vtx_handle;
        edm::EDGetTokenT<reco::VertexCollection> vtx_token;

    private:
        panda::PEvent *data;
        TString treename;
};
}


#endif
