#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    CStringView view;
    char* payload;
    size_t cap;


    void evaluate(Context ctx) {
        if (isSettingUp()) {
            cap = getValue<input_Size>(ctx) * 2 + 1;
            payload = new char[cap];
            view = CStringView(payload);
        }

        if (isInputDirty<input_UPD>(ctx)) {
            auto lpp = getValue<input_LPP>(ctx);
            uint8_t* buff = lpp->getBuffer();
            uint8_t N = lpp->getSize();
            memset(payload, '\0', cap);
            for (uint8_t i=0;i<N;i++) {
                payload[i * 2] = "0123456789ABCDEF"[*(buff+i) / 16];
                payload[i * 2 + 1] = "0123456789ABCDEF"[*(buff+i) % 16];
            }
            emitValue<output_PYLD>(ctx, XString(&view));
            emitValue<output_Done>(ctx, 1);
        }


    }
}
