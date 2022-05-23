#ifndef INTERNALEVENTS_H
#define INTERNALEVENTS_H


struct InternalEvents
{
    enum Identifiers {
        UNKNOWN, // Must always be first, used to check for bounds of enum input value

        ON_TICK, // We'll use CApp::OnLoop for this ticking

        UNKNOWN_MAX // Must always be last, used to check for bounds of enum input value
    };
};

// TODO: Maybe we store an array using the Identifiers as the index and store the additional call data in there? Like number of arguments etc...?
/* Example
// NOTE: Should exclude/ignore this from Lua (defines.i) so that the CallData is not available
struct InternalEvent_CallData {
    unsigned int argCount;
    bool isVariableArgs;
}
static InternalEvent_CallData CallData[InternalEvents::UNKNOWN_MAX - 1];
CallData[ON_TICK] = { 0, false };
};
*/

#endif // INTERNALEVENTS_H
