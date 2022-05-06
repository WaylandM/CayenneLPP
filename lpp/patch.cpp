#pragma XOD require "https://github.com/ElectronicCats/CayenneLPP"

#include <CayenneLPP.h>

node {
    meta {
        using Type = CayenneLPP*;
    }

    uint8_t mem[sizeof(CayenneLPP)];

    void evaluate(Context ctx) {
        if (!isSettingUp()) return;
        uint8_t size = getValue<input_Size>(ctx);
        Type lpp = new (mem) CayenneLPP(size);
        emitValue<output_LPP>(ctx, lpp);
    }
}
