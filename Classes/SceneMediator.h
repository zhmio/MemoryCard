//
//  SceneMediator.h
//  MemoryCards
//
//  Created by zh on 15-7-17.
//
//

#ifndef __MemoryCards__SceneMediator__
#define __MemoryCards__SceneMediator__

#include <stdio.h>

class SceneMediator {
protected:
    static SceneMediator* _instance;
    
public:
    static SceneMediator* getInstance();
    virtual void gotoStartScene();
    virtual void gotoChartScene();
    virtual void gotoGameScene();
};

#endif /* defined(__MemoryCards__SceneMediator__) */
