-module(class_TrackElement_TrackElementStation).
-include_lib("../include/abs_types.hrl").
-behaviour(object).
-export([get_val_internal/2,set_val_internal/3,init_internal/0,get_state_for_modelapi/1]).
-compile(export_all).

exported() -> #{  }.

'init'(O=#object{class=class_TrackElement_TrackElementStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},[P_name,Stack])->
    put(vars, #{}),
    set(O,'name',P_name),
     %% src/TrackElement.abs:211--211
    set(O,'tr',null),
     %% src/TrackElement.abs:212--212
    set(O,'pre',[]),
    O.
 %% src/TrackElement.abs:214
 %% src/TrackElement.abs:214
'm_printName'(O=#object{class=class_TrackElement_TrackElementStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
         %% src/TrackElement.abs:215--215
        T_1 = builtin:println(Cog,<<"TrackElement Station Track"/utf8>>),
        T_1,
         %% src/TrackElement.abs:216--216
        T_2 = builtin:println(Cog,get(O,'name')),
        T_2
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method printName and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:219
 %% src/TrackElement.abs:219
'm_getType'(O=#object{class=class_TrackElement_TrackElementStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
         %% src/TrackElement.abs:220--220
        dataStation
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method getType and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:223
 %% src/TrackElement.abs:223
'm_getName'(O=#object{class=class_TrackElement_TrackElementStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
         %% src/TrackElement.abs:224--224
        get(O,'name')
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method getName and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:226
 %% src/TrackElement.abs:226
'm_getSignal'(O=#object{class=class_TrackElement_TrackElementStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_id_0,Stack)->
    put(vars, #{ 'this' => O,
 'id' => V_id_0 }),
    try
         %% src/TrackElement.abs:227--227
        put(vars, (get(vars))#{'retVal' => null}),
         %% src/TrackElement.abs:228--228
        maps:get('retVal', get(vars))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method getSignal and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:231
 %% src/TrackElement.abs:231
'm_getTrackElement'(O=#object{class=class_TrackElement_TrackElementStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_id_0,Stack)->
    put(vars, #{ 'this' => O,
 'id' => V_id_0 }),
    try
         %% src/TrackElement.abs:232--232
        put(vars, (get(vars))#{'retVal' => m_ABS_StdLib_funs:f_nth(Cog,get(O,'pre'),maps:get('id', get(vars)),[O,DC| Stack])}),
         %% src/TrackElement.abs:233--233
        maps:get('retVal', get(vars))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method getTrackElement and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:235
 %% src/TrackElement.abs:235
'm_forceSet'(O=#object{class=class_TrackElement_TrackElementStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_t_0,V_id_0,Stack)->
    put(vars, #{ 'this' => O,
 't' => V_t_0,
 'id' => V_id_0 }),
    try
        ok
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method forceSet and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:238
 %% src/TrackElement.abs:238
'm_registerTrain'(O=#object{class=class_TrackElement_TrackElementStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_tr_0,V_p_0,Stack)->
    put(vars, #{ 'this' => O,
 'tr' => V_tr_0,
 'p' => V_p_0 }),
    try
         %% src/TrackElement.abs:239--239
        T_1 = builtin:println(Cog,<<"register train on a trackelement station"/utf8>>),
        T_1,
         %% src/TrackElement.abs:240--240
        -1
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method registerTrain and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:242
 %% src/TrackElement.abs:242
'm_registerDriveOut'(O=#object{class=class_TrackElement_TrackElementStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_tr_0,Stack)->
    put(vars, #{ 'this' => O,
 'tr' => V_tr_0 }),
    try
        ok
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method registerDriveOut and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:245
 %% src/TrackElement.abs:245
'm_forceSignal'(O=#object{class=class_TrackElement_TrackElementStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_id_0,V_s_0,Stack)->
    put(vars, #{ 'this' => O,
 'id' => V_id_0,
 's' => V_s_0 }),
    try
        ok
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method forceSignal and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:248
 %% src/TrackElement.abs:248
'm_construct'(O=#object{class=class_TrackElement_TrackElementStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_pre_0,V_stations_0,Stack)->
    put(vars, #{ 'this' => O,
 'pre' => V_pre_0,
 'stations' => V_stations_0 }),
    try
         %% src/TrackElement.abs:249--249
        set(O,'pre',maps:get('pre', get(vars))),
         %% src/TrackElement.abs:250--250
        true
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method construct and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:253
 %% src/TrackElement.abs:253
'm_occupy'(O=#object{class=class_TrackElement_TrackElementStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_t_0,V_p_0,Stack)->
    put(vars, #{ 'this' => O,
 't' => V_t_0,
 'p' => V_p_0 }),
    try
         %% src/TrackElement.abs:254--254
        put(vars, (get(vars))#{'retVal' => false}),
         %% src/TrackElement.abs:255--255
        maps:get('retVal', get(vars))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method occupy and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:258
 %% src/TrackElement.abs:258
'm_drive_in'(O=#object{class=class_TrackElement_TrackElementStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_tr_0,Stack)->
    put(vars, #{ 'this' => O,
 'tr' => V_tr_0 }),
    try
        ok
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method drive_in and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
'set'(O=#object{class=class_TrackElement_TrackElementStation=C,ref=Ref,cog=Cog},Var,Val)->
    object:set_field_value(O, Var, Val).

'get'(O=#object{class=class_TrackElement_TrackElementStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Var)->
    object:get_field_value(O,Var).

-record(state,{'name'=null,'tr'=null,'pre'=null}).
'init_internal'()->
    #state{}.

 %% src/TrackElement.abs:210
'get_val_internal'(#state{'name'=G},'name')->
    G;
 %% src/TrackElement.abs:211
'get_val_internal'(#state{'tr'=G},'tr')->
    G;
 %% src/TrackElement.abs:212
'get_val_internal'(#state{'pre'=G},'pre')->
    G;
'get_val_internal'(_,_)->
    %% Invalid return value; handled by HTTP API when querying for non-existant field.
    %% Will never occur in generated code.
    none.

 %% src/TrackElement.abs:210
'set_val_internal'(S,'name',V)->
    S#state{'name'=V};
 %% src/TrackElement.abs:211
'set_val_internal'(S,'tr',V)->
    S#state{'tr'=V};
 %% src/TrackElement.abs:212
'set_val_internal'(S,'pre',V)->
    S#state{'pre'=V}.

'get_state_for_modelapi'(S)->
    [
        { 'name', S#state.'name' }
        , { 'tr', S#state.'tr' }
        , { 'pre', S#state.'pre' }
    ].
