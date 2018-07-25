-module(class_Signal_SignalAusfahrt).
-include_lib("../include/abs_types.hrl").
-behaviour(object).
-export([get_val_internal/2,set_val_internal/3,init_internal/0,get_state_for_modelapi/1]).
-compile(export_all).

exported() -> #{  }.

'init'(O=#object{class=class_Signal_SignalAusfahrt=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},[Stack])->
    put(vars, #{}),
     %% src/Signal.abs:59--59
    set(O,'signal',dataRED),
     %% src/Signal.abs:60--60
    set(O,'train',null),
     %% src/Signal.abs:61--61
    set(O,'track',null),
    O.
 %% src/Signal.abs:63
 %% src/Signal.abs:63
'm_construct'(O=#object{class=class_Signal_SignalAusfahrt=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_t_0,Stack)->
    put(vars, #{ 'this' => O,
 't' => V_t_0 }),
    try
         %% src/Signal.abs:64--64
        set(O,'track',maps:get('t', get(vars)))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method construct and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Signal.abs:67
 %% src/Signal.abs:67
'm_forceSignal'(O=#object{class=class_Signal_SignalAusfahrt=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_s_0,Stack)->
    put(vars, #{ 'this' => O,
 's' => V_s_0 }),
    try
         %% src/Signal.abs:68--68
        set(O,'signal',maps:get('s', get(vars))),
         %% src/Signal.abs:69--69
        T_1 = future:start(O,'m_notifyTrain',[[]],#process_info{method= <<"notifyTrain"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack]),
        T_1
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method forceSignal and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Signal.abs:72
 %% src/Signal.abs:72
'm_registerTrain'(O=#object{class=class_Signal_SignalAusfahrt=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_tr_0,Stack)->
    put(vars, #{ 'this' => O,
 'tr' => V_tr_0 }),
    try
         %% src/Signal.abs:73--73
        set(O,'train',maps:get('tr', get(vars)))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method registerTrain and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Signal.abs:76
 %% src/Signal.abs:76
'm_notifyTrain'(O=#object{class=class_Signal_SignalAusfahrt=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
         %% src/Signal.abs:77--77
        case (not cmp:eq(get(O,'train'),null)) of
            true ->  %% src/Signal.abs:78--78
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
             %% src/Signal.abs:79--79
            set(O,'train',null);
            false ->         ok
        end
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method notifyTrain and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Signal.abs:83
 %% src/Signal.abs:83
'm_vorblock'(O=#object{class=class_Signal_SignalAusfahrt=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
        ok
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method vorblock and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Signal.abs:86
 %% src/Signal.abs:86
'm_rueckblock'(O=#object{class=class_Signal_SignalAusfahrt=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
        ok
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method rueckblock and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
'set'(O=#object{class=class_Signal_SignalAusfahrt=C,ref=Ref,cog=Cog},Var,Val)->
    object:set_field_value(O, Var, Val).

'get'(O=#object{class=class_Signal_SignalAusfahrt=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Var)->
    object:get_field_value(O,Var).

-record(state,{'signal'=null,'train'=null,'track'=null}).
'init_internal'()->
    #state{}.

 %% src/Signal.abs:59
'get_val_internal'(#state{'signal'=G},'signal')->
    G;
 %% src/Signal.abs:60
'get_val_internal'(#state{'train'=G},'train')->
    G;
 %% src/Signal.abs:61
'get_val_internal'(#state{'track'=G},'track')->
    G;
'get_val_internal'(_,_)->
    %% Invalid return value; handled by HTTP API when querying for non-existant field.
    %% Will never occur in generated code.
    none.

 %% src/Signal.abs:59
'set_val_internal'(S,'signal',V)->
    S#state{'signal'=V};
 %% src/Signal.abs:60
'set_val_internal'(S,'train',V)->
    S#state{'train'=V};
 %% src/Signal.abs:61
'set_val_internal'(S,'track',V)->
    S#state{'track'=V}.

'get_state_for_modelapi'(S)->
    [
        { 'signal', S#state.'signal' }
        , { 'train', S#state.'train' }
        , { 'track', S#state.'track' }
    ].
