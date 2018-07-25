-module(class_Signal_SignalEinfahrt).
-include_lib("../include/abs_types.hrl").
-behaviour(object).
-export([get_val_internal/2,set_val_internal/3,init_internal/0,get_state_for_modelapi/1]).
-compile(export_all).

exported() -> #{  }.

'init'(O=#object{class=class_Signal_SignalEinfahrt=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},[Stack])->
    put(vars, #{}),
     %% src/Signal.abs:93--93
    set(O,'signal',dataRED),
     %% src/Signal.abs:94--94
    set(O,'track',null),
     %% src/Signal.abs:95--95
    set(O,'train',null),
    O.
 %% src/Signal.abs:97
 %% src/Signal.abs:97
'm_construct'(O=#object{class=class_Signal_SignalEinfahrt=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_t_0,Stack)->
    put(vars, #{ 'this' => O,
 't' => V_t_0 }),
    try
         %% src/Signal.abs:98--98
        set(O,'track',maps:get('t', get(vars)))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method construct and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Signal.abs:101
 %% src/Signal.abs:101
'm_forceSignal'(O=#object{class=class_Signal_SignalEinfahrt=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_s_0,Stack)->
    put(vars, #{ 'this' => O,
 's' => V_s_0 }),
    try
         %% src/Signal.abs:102--102
        set(O,'signal',maps:get('s', get(vars))),
         %% src/Signal.abs:103--103
        T_1 = future:start(O,'m_notifyTrain',[[]],#process_info{method= <<"notifyTrain"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack]),
        T_1
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method forceSignal and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Signal.abs:106
 %% src/Signal.abs:106
'm_registerTrain'(O=#object{class=class_Signal_SignalEinfahrt=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_tr_0,Stack)->
    put(vars, #{ 'this' => O,
 'tr' => V_tr_0 }),
    try
         %% src/Signal.abs:107--107
        set(O,'train',maps:get('tr', get(vars)))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method registerTrain and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Signal.abs:110
 %% src/Signal.abs:110
'm_notifyTrain'(O=#object{class=class_Signal_SignalEinfahrt=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
         %% src/Signal.abs:111--111
        case (not cmp:eq(get(O,'train'),null)) of
            true ->  %% src/Signal.abs:112--112
            T_1 = (fun() -> case get(O,'train') of
                null -> throw(dataNullPointerException);
                #object{ref=ObjRef,class=T,cog=Cog} ->
                    case is_process_alive(ObjRef) of
                        true ->
                            Vars=get(vars),
                            Result=T:'m_signalChanged'(get(O,'train'),get(O,'signal'),get(O,'track'),[O,DC| Stack]),
                            put(vars, Vars),
                            Result;
                        false -> throw(dataObjectDeadException)
                    end;
                _ ->
                    TempFuture = future:start(get(O,'train'),'m_signalChanged',[get(O,'signal'),get(O,'track'),[]],#process_info{method= <<"signalChanged"/utf8>>},Cog,[O,DC| Stack]),
                    future:get_blocking(TempFuture, Cog, [O,DC| Stack])
            end end)(),
            T_1,
             %% src/Signal.abs:113--113
            set(O,'train',null);
            false ->         ok
        end
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method notifyTrain and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Signal.abs:118
 %% src/Signal.abs:118
'm_vorblock'(O=#object{class=class_Signal_SignalEinfahrt=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
        ok
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method vorblock and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Signal.abs:122
 %% src/Signal.abs:122
'm_rueckblock'(O=#object{class=class_Signal_SignalEinfahrt=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
        ok
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method rueckblock and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
'set'(O=#object{class=class_Signal_SignalEinfahrt=C,ref=Ref,cog=Cog},Var,Val)->
    object:set_field_value(O, Var, Val).

'get'(O=#object{class=class_Signal_SignalEinfahrt=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Var)->
    object:get_field_value(O,Var).

-record(state,{'signal'=null,'track'=null,'train'=null}).
'init_internal'()->
    #state{}.

 %% src/Signal.abs:93
'get_val_internal'(#state{'signal'=G},'signal')->
    G;
 %% src/Signal.abs:94
'get_val_internal'(#state{'track'=G},'track')->
    G;
 %% src/Signal.abs:95
'get_val_internal'(#state{'train'=G},'train')->
    G;
'get_val_internal'(_,_)->
    %% Invalid return value; handled by HTTP API when querying for non-existant field.
    %% Will never occur in generated code.
    none.

 %% src/Signal.abs:93
'set_val_internal'(S,'signal',V)->
    S#state{'signal'=V};
 %% src/Signal.abs:94
'set_val_internal'(S,'track',V)->
    S#state{'track'=V};
 %% src/Signal.abs:95
'set_val_internal'(S,'train',V)->
    S#state{'train'=V}.

'get_state_for_modelapi'(S)->
    [
        { 'signal', S#state.'signal' }
        , { 'track', S#state.'track' }
        , { 'train', S#state.'train' }
    ].
