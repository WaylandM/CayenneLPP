#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {

    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;
        auto lpp = getValue<input_LPP>(ctx);
        auto color = getValue<input_Color>(ctx);
        lpp->addColour(
            getValue<input_CHL>(ctx),
            color.r, color.g, color.b);
        emitValue<output_Done>(ctx, 1);
    }
}
