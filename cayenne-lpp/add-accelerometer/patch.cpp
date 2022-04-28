#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {

    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;
        auto lpp = getValue<input_LPP>(ctx);
        lpp->addAccelerometer(
            getValue<input_CHL>(ctx),
            getValue<input_X>(ctx),
            getValue<input_Y>(ctx),
            getValue<input_Z>(ctx));
        emitValue<output_Done>(ctx, 1);
    }
}
