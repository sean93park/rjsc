// codes are from;
// https://developer.mozilla.org/en-US/docs/Mozilla/Projects/SpiderMonkey/JSAPI_User_Guide
// https://developer.mozilla.org/en-US/docs/How_to_embed_the_JavaScript_engine
//
#include "jsapi.h"

/* The class of the global object. */
static JSClass global_class = { 
    "global",
    JSCLASS_NEW_RESOLVE | JSCLASS_GLOBAL_FLAGS,
    JS_PropertyStub,
    JS_DeletePropertyStub,
    JS_PropertyStub,
    JS_StrictPropertyStub,
    JS_EnumerateStub,
    JS_ResolveStub,
    JS_ConvertStub,
    nullptr,
    JSCLASS_NO_OPTIONAL_MEMBERS
};

/* The error reporter callback. */
void reportError(JSContext *cx, const char *message, JSErrorReport *report)
{
     fprintf(stderr, "%s:%u:%s\n",
             report->filename ? report->filename : "[no filename]",
             (unsigned int) report->lineno,
             message);
}

int run(JSContext *cx)
{
    /* Enter a request before running anything in the context */
    JSAutoRequest ar(cx);

    /* Create the global object in a new compartment. */
    JSObject *global = JS_NewGlobalObject(cx, &global_class, nullptr);
    if (!global)
        return 1;

    /* Set the context's global */
    JSAutoCompartment ac(cx, global);
    JS_SetGlobalObject(cx, global);

    /* Populate the global object with the standard globals, like Object and Array. */
    if (!JS_InitStandardClasses(cx, global))
        return 1;

    /* Your application code here. This may include JSAPI calls to create your own custom JS objects and run scripts. */
    JS::Value rval;
    bool ok;
    {
        JSAutoCompartment ac(cx, global); 
        JS_InitStandardClasses(cx, global);

        const char *script = "'hello'+'world, it is '+new Date()";
        const char *filename = "noname";
        int lineno = 0;
        ok = JS_EvaluateScript(cx, global, script, strlen(script), filename, lineno, &rval);
        if (rval.isNull() || rval.isFalse() )
            return 1;
    }

    JSString *str = rval.toString();
    printf("%s\n", JS_EncodeString(cx, str));

    return 0;
}

int main(int argc, const char *argv[])
{
    /* Initialize the JS engine -- new/required as of SpiderMonkey 31. */
    //if (!JS_Init())
    //   return 1;

    /* Create a JS runtime. */
    JSRuntime *rt = JS_NewRuntime(8L * 1024L * 1024L, JS_NO_HELPER_THREADS);
    if (!rt)
       return 1;

    /* Create a context. */
    JSContext *cx = JS_NewContext(rt, 8192);
    if (!cx)
       return 1;
    JS_SetOptions(cx, JSOPTION_VAROBJFIX);
    JS_SetErrorReporter(cx, reportError);

    int status = run(cx);

    JS_DestroyContext(cx);
    JS_DestroyRuntime(rt);

    /* Shut down the JS engine. */
    JS_ShutDown();

    return status;
}