-module(class_Signal_SignalFreeWay).
-include_lib("../include/abs_types.hrl").
-behaviour(object).
-export([get_val_internal/2,set_val_internal/3,init_internal/0,get_state_for_modelapi/1]).
-compile(export_all).

exported() -> #{  }.

'init'(O=#object{class=class_Signal_SignalFreeWay=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},[Stack])->
    put(vars, #{}),
     %% src/Signal.abs:20--20
    set(O,'track',null),
     %% src/Signal.abs:21--21
    set(O,'signal',dataRED),
     %% src/Signal.abs:22--22
    set(O,'train',null),
     %% src/Signal.abs:23--23
    set(O,'vorblock',0),
    O.
 %% src/Signal.abs:25
 %% src/Signal.abs:25
'm_construct'(O=#object{class=class_Signal_SignalFreeWay=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_t_0,Stack)->
    put(vars, #{ 'this' => O,
 't' => V_t_0 }),
    try
         %% src/Signal.abs:26--26
        set(O,'track',maps:get('t', get(vars)))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method construct and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Signal.abs:29
 %% src/Signal.abs:29
'm_notifyTrain'(O=#object{class=class_Signal_SignalFreeWay=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
         %% src/Signal.abs:30--30
        task:release_token(Cog,waiting_poll),
        (fun Poll ([])->
            receive check -> 
                case (not cmp:eq(get(O,'train'),null)) of
                    true -> cog:process_poll_is_ready(Cog, self(), get(process_info)), Poll([]);
                    false -> cog:process_poll_is_not_ready(Cog, self(), get(process_info)),  Poll([])
                end;
            wait -> Poll([]);
            token -> ok;
            {stop_world, _Sender} -> % only happens when stop_world and release_token cross
                Poll([]);
            {get_references, Sender} ->
                cog:submit_references(Sender, gc:extract_references([O,DC| Stack])),
                Poll([]);
            die_prematurely ->
                task:send_notifications(killed_by_the_clock),
                exit(killed_by_the_clock)
        end end)
    ([]),
     %% src/Signal.abs:31--31
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
     %% src/Signal.abs:32--32
    set(O,'train',null)
catch
    _:Exception ->
        io:format(standard_error, "Uncaught ~s in method notifyTrain and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
        object:die(O, Exception), exit(Exception)
end.
 %% src/Signal.abs:35
 %% src/Signal.abs:35
'm_vorblock'(O=#object{class=class_Signal_SignalFreeWay=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
         %% src/Signal.abs:37--37
        set(O,'vorblock',1),
         %% src/Signal.abs:38--38
        T_1 = (fun() -> case O of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_forceSignal'(O,dataGREEN,[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(O,'m_forceSignal',[dataGREEN,[]],#process_info{method= <<"forceSignal"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)(),
        T_1
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method vorblock and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Signal.abs:41
 %% src/Signal.abs:41
'm_rueckblock'(O=#object{class=class_Signal_SignalFreeWay=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
         %% src/Signal.abs:42--42
        T_1 = (fun() -> case O of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_forceSignal'(O,dataRED,[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(O,'m_forceSignal',[dataRED,[]],#process_info{method= <<"forceSignal"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)(),
        T_1,
         %% src/Signal.abs:43--43
        set(O,'train',null),
         %% src/Signal.abs:44--44
        set(O,'vorblock',0)
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method rueckblock and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Signal.abs:46
 %% src/Signal.abs:46
'm_forceSignal'(O=#object{class=class_Signal_SignalFreeWay=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_s_0,Stack)->
    put(vars, #{ 'this' => O,
 's' => V_s_0 }),
    try
         %% src/Signal.abs:47--47
        set(O,'signal',maps:get('s', get(vars))),
         %% src/Signal.abs:48--48
        T_1 = future:start(O,'m_notifyTrain',[[]],#process_info{method= <<"notifyTrain"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack]),
        T_1
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method forceSignal and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Signal.abs:51
 %% src/Signal.abs:51
'm_registerTrain'(O=#object{class=class_Signal_SignalFreeWay=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_tr_0,Stack)->
    put(vars, #{ 'this' => O,
 'tr' => V_tr_0 }),
    try
         %% src/Signal.abs:52--52
        set(O,'train',maps:get('tr', get(vars)))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method registerTrain and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
'set'(O=#object{class=class_Signal_SignalFreeWay=C,ref=Ref,cog=Cog},Var,Val)->
    object:set_field_value(O, Var, Val).

'get'(O=#object{class=class_Signal_SignalFreeWay=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Var)->
    object:get_field_value(O,Var).

-record(state,{'track'=null,'signal'=null,'train'=null,'vorblock'=null}).
'init_internal'()->
    #state{}.

 %% src/Signal.abs:20
'get_val_internal'(#state{'track'=G},'track')->
    G;
 %% src/Signal.abs:21
'get_val_internal'(#state{'signal'=G},'signal')->
    G;
 %% src/Signal.abs:22
'get_val_internal'(#state{'train'=G},'train')->
    G;
 %% src/Signal.abs:23
'get_val_internal'(#state{'vorblock'=G},'vorblock')->
    G;
'get_val_internal'(_,_)->
    %% Invalid return value; handled by HTTP API when querying for non-existant field.
    %% Will never occur in generated code.
    none.

 %% src/Signal.abs:20
'set_val_internal'(S,'track',V)->
    S#state{'track'=V};
 %% src/Signal.abs:21
'set_val_internal'(S,'signal',V)->
    S#state{'signal'=V};
 %% src/Signal.abs:22
'set_val_internal'(S,'train',V)->
    S#state{'train'=V};
 %% src/Signal.abs:23
'set_val_internal'(S,'vorblock',V)->
    S#state{'vorblock'=V}.

'get_state_for_modelapi'(S)->
    [
        { 'track', S#state.'track' }
        , { 'signal', S#state.'signal' }
        , { 'train', S#state.'train' }
        , { 'vorblock', S#state.'vorblock' }
    ].
