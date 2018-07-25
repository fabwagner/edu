-module(class_Train_TrainImpl).
-include_lib("../include/abs_types.hrl").
-behaviour(object).
-export([get_val_internal/2,set_val_internal/3,init_internal/0,get_state_for_modelapi/1]).
-compile(export_all).

exported() -> #{  }.

'init'(O=#object{class=class_Train_TrainImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},[P_id,Stack])->
    put(vars, #{}),
    set(O,'id',P_id),
     %% src/Train.abs:26--26
    set(O,'state',-1),
     %% src/Train.abs:27--27
     %% src/Train.abs:28--28
     %% src/Train.abs:29--29
    set(O,'start',false),
     %% src/Train.abs:30--30
    set(O,'s2',false),
     %% src/Train.abs:31--31
    set(O,'nextSet',false),
     %% src/Train.abs:33--33
    set(O,'next',null),
     %% src/Train.abs:34--34
    set(O,'last',null),
    cog:process_is_blocked_for_gc(Cog, self()),
    cog:add_sync(Cog,active_object_task,none,O,[],#process_info{method= <<"run"/utf8>>},[O,DC| Stack]),
    cog:process_is_runnable(Cog,self()),
    task:wait_for_token(Cog,[O,DC| Stack]),
    O.
 %% src/Train.abs:37
 %% src/Train.abs:37
'm_registerInStation'(O=#object{class=class_Train_TrainImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_st_0,Stack)->
    put(vars, #{ 'this' => O,
 'st' => V_st_0 }),
    try
         %% src/Train.abs:38--38
        put(vars, (get(vars))#{'name' => (fun() -> case maps:get('st', get(vars)) of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_getName'(maps:get('st', get(vars)),[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(maps:get('st', get(vars)),'m_getName',[[]],#process_info{method= <<"getName"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)()}),
         %% src/Train.abs:39--39
        T_1 = builtin:println(Cog,iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([<<"-> ["/utf8>>, builtin:toString(Cog,get(O,'id'))]), <<"].registerInStation("/utf8>>]), maps:get('name', get(vars))]), <<")"/utf8>>])),
        T_1,
         %% src/Train.abs:41--41
        put(vars, (get(vars))#{'retVal' => false}),
         %% src/Train.abs:42--42
        put(vars, (get(vars))#{'tmp2009492047' => future:start(maps:get('st', get(vars)),'m_register',[O,[]],#process_info{method= <<"register"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack])}),
         %% src/Train.abs:42--42
        future:await(maps:get('tmp2009492047', get(vars)), Cog, [O,DC| Stack]),
        ok,
         %% src/Train.abs:42--42
        put(vars, (get(vars))#{'reg' => future:get_blocking(maps:get('tmp2009492047', get(vars)), Cog, [O,DC| Stack])}),
         %% src/Train.abs:43--43
        case maps:get('reg', get(vars)) of
            true ->  %% src/Train.abs:44--44
            set(O,'station',maps:get('st', get(vars))),
             %% src/Train.abs:45--45
            set(O,'state',0);
            false ->          %% src/Train.abs:47--47
        T_2 = builtin:println(Cog,<<"Train could not be registered."/utf8>>),
        T_2
        end,
         %% src/Train.abs:49--49
        put(vars, (get(vars))#{'retVal' := maps:get('reg', get(vars))}),
         %% src/Train.abs:50--50
        maps:get('retVal', get(vars))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method registerInStation and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Train.abs:53
 %% src/Train.abs:53
'm_setNext'(O=#object{class=class_Train_TrainImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_n_0,Stack)->
    put(vars, #{ 'this' => O,
 'n' => V_n_0 }),
    try
         %% src/Train.abs:54--54
        put(vars, (get(vars))#{'name' => (fun() -> case maps:get('n', get(vars)) of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_getName'(maps:get('n', get(vars)),[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(maps:get('n', get(vars)),'m_getName',[[]],#process_info{method= <<"getName"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)()}),
         %% src/Train.abs:55--55
        T_1 = builtin:println(Cog,iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([<<"-> ["/utf8>>, builtin:toString(Cog,get(O,'id'))]), <<"].setNext("/utf8>>]), maps:get('name', get(vars))]), <<")"/utf8>>])),
        T_1,
         %% src/Train.abs:57--57
        set(O,'last',get(O,'next')),
         %% src/Train.abs:58--58
        set(O,'next',maps:get('n', get(vars))),
         %% src/Train.abs:59--59
        set(O,'nextSet',true)
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method setNext and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Train.abs:62
 %% src/Train.abs:62
'm_setDriveInStation'(O=#object{class=class_Train_TrainImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_st_0,Stack)->
    put(vars, #{ 'this' => O,
 'st' => V_st_0 }),
    try
         %% src/Train.abs:63--63
        put(vars, (get(vars))#{'name' => (fun() -> case maps:get('st', get(vars)) of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_getName'(maps:get('st', get(vars)),[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(maps:get('st', get(vars)),'m_getName',[[]],#process_info{method= <<"getName"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)()}),
         %% src/Train.abs:64--64
        T_1 = builtin:println(Cog,iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([<<"-> ["/utf8>>, builtin:toString(Cog,get(O,'id'))]), <<"].setDriveInStation("/utf8>>]), maps:get('name', get(vars))]), <<")"/utf8>>])),
        T_1,
         %% src/Train.abs:65--65
        set(O,'driveIn',maps:get('st', get(vars)))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method setDriveInStation and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Train.abs:68
 %% src/Train.abs:68
'm_setDriveIn'(O=#object{class=class_Train_TrainImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_t_0,Stack)->
    put(vars, #{ 'this' => O,
 't' => V_t_0 }),
    try
         %% src/Train.abs:69--69
        put(vars, (get(vars))#{'name' => (fun() -> case maps:get('t', get(vars)) of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_getName'(maps:get('t', get(vars)),[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(maps:get('t', get(vars)),'m_getName',[[]],#process_info{method= <<"getName"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)()}),
         %% src/Train.abs:70--70
        T_1 = builtin:println(Cog,iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([<<"-> ["/utf8>>, builtin:toString(Cog,get(O,'id'))]), <<"].setDriveIn("/utf8>>]), maps:get('name', get(vars))]), <<")"/utf8>>])),
        T_1,
         %% src/Train.abs:72--72
        set(O,'last',get(O,'next')),
         %% src/Train.abs:73--73
        set(O,'next',maps:get('t', get(vars))),
         %% src/Train.abs:74--74
        set(O,'state',2),
         %% src/Train.abs:75--75
        set(O,'nextSet',true)
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method setDriveIn and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Train.abs:78
 %% src/Train.abs:78
'm_start'(O=#object{class=class_Train_TrainImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
         %% src/Train.abs:79--79
        T_1 = builtin:println(Cog,iolist_to_binary([iolist_to_binary([<<"-> ["/utf8>>, builtin:toString(Cog,get(O,'id'))]), <<"].start()"/utf8>>])),
        T_1,
         %% src/Train.abs:80--80
        set(O,'start',true)
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method start and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Train.abs:83
 %% src/Train.abs:83
'm_drive_out'(O=#object{class=class_Train_TrainImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
         %% src/Train.abs:84--84
        T_1 = builtin:println(Cog,iolist_to_binary([iolist_to_binary([<<"-> ["/utf8>>, builtin:toString(Cog,get(O,'id'))]), <<"].drive_out()"/utf8>>])),
        T_1,
         %% src/Train.abs:85--85
        set(O,'state',1)
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method drive_out and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Train.abs:88
 %% src/Train.abs:88
'm_drive_in'(O=#object{class=class_Train_TrainImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_st_0,Stack)->
    put(vars, #{ 'this' => O,
 'st' => V_st_0 }),
    try
         %% src/Train.abs:89--89
        put(vars, (get(vars))#{'name' => (fun() -> case maps:get('st', get(vars)) of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_getName'(maps:get('st', get(vars)),[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(maps:get('st', get(vars)),'m_getName',[[]],#process_info{method= <<"getName"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)()}),
         %% src/Train.abs:90--90
        T_1 = builtin:println(Cog,iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([<<"-> ["/utf8>>, builtin:toString(Cog,get(O,'id'))]), <<"].drive_in("/utf8>>]), maps:get('name', get(vars))]), <<")"/utf8>>])),
        T_1,
         %% src/Train.abs:92--92
        set(O,'station',maps:get('st', get(vars))),
         %% src/Train.abs:93--93
        set(O,'last',null),
         %% src/Train.abs:94--94
        set(O,'next',null),
         %% src/Train.abs:95--95
        set(O,'nextSet',true),
         %% src/Train.abs:96--96
        set(O,'state',0)
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method drive_in and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Train.abs:99
 %% src/Train.abs:99
'm_run'(O=#object{class=class_Train_TrainImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
         %% src/Train.abs:100--100
        T_1 = builtin:println(Cog,iolist_to_binary([iolist_to_binary([<<"-> ["/utf8>>, builtin:toString(Cog,get(O,'id'))]), <<"].run()"/utf8>>])),
        T_1,
         %% src/Train.abs:102--102
        task:release_token(Cog,waiting_poll),
        (fun Poll ([])->
            receive check -> 
                case get(O,'start') of
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
     %% src/Train.abs:103--103
    case cmp:eq(get(O,'state'),0) of
        true ->  %% src/Train.abs:104--104
        T_2 = future:start(get(O,'station'),'m_askDriveOut',[O,0,[]],#process_info{method= <<"askDriveOut"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack]),
        T_2;
        false ->      %% src/Train.abs:106--106
    case cmp:eq(get(O,'state'),1) of
        true ->  %% src/Train.abs:107--107
        T_2 = future:start(get(O,'next'),'m_occupy',[O,get(O,'last'),[]],#process_info{method= <<"occupy"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack]),
        T_2,
         %% src/Train.abs:108--108
        task:release_token(Cog,waiting_poll),
        (fun Poll ([])->
            receive check -> 
                case get(O,'nextSet') of
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
     %% src/Train.abs:109--109
    set(O,'nextSet',false);
    false ->      %% src/Train.abs:110--110
    case cmp:eq(get(O,'state'),2) of
        true ->  %% src/Train.abs:111--111
        T_2 = (fun() -> case get(O,'driveIn') of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_driveIn'(get(O,'driveIn'),O,get(O,'station'),[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(get(O,'driveIn'),'m_driveIn',[O,get(O,'station'),[]],#process_info{method= <<"driveIn"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)(),
        T_2;
        false ->     ok
    end
end
    end
catch
    _:Exception ->
        io:format(standard_error, "Uncaught ~s in method run and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
        object:die(O, Exception), exit(Exception)
end.
 %% src/Train.abs:115
 %% src/Train.abs:115
'm_signalChanged'(O=#object{class=class_Train_TrainImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_s_0,V_t_0,Stack)->
    put(vars, #{ 'this' => O,
 's' => V_s_0,
 't' => V_t_0 }),
    try
         %% src/Train.abs:116--116
        put(vars, (get(vars))#{'name' => (fun() -> case maps:get('t', get(vars)) of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_getName'(maps:get('t', get(vars)),[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(maps:get('t', get(vars)),'m_getName',[[]],#process_info{method= <<"getName"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)()}),
         %% src/Train.abs:117--117
        put(vars, (get(vars))#{'color' => <<"GREEN"/utf8>>}),
         %% src/Train.abs:118--118
        case cmp:eq(maps:get('s', get(vars)),dataRED) of
            true ->  %% src/Train.abs:119--119
            put(vars, (get(vars))#{'color' := <<"RED"/utf8>>});
            false ->         ok
        end,
         %% src/Train.abs:120--120
        T_1 = builtin:println(Cog,iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([<<"-> ["/utf8>>, builtin:toString(Cog,get(O,'id'))]), <<"].signalChanged("/utf8>>]), maps:get('name', get(vars))]), <<", "/utf8>>]), maps:get('color', get(vars))]), <<")"/utf8>>])),
        T_1,
         %% src/Train.abs:122--122
        case cmp:eq(maps:get('s', get(vars)),dataGREEN) of
            true ->  %% src/Train.abs:123--123
            case cmp:eq(maps:get('t', get(vars)),get(O,'next')) of
                true ->  %% src/Train.abs:124--124
                T_2 = (fun() -> case O of
                    null -> throw(dataNullPointerException);
                    #object{ref=ObjRef,class=T,cog=Cog} ->
                        case is_process_alive(ObjRef) of
                            true ->
                                Vars=get(vars),
                                Result=T:'m_run'(O,[O,DC| Stack]),
                                put(vars, Vars),
                                Result;
                            false -> throw(dataObjectDeadException)
                        end;
                    _ ->
                        TempFuture = future:start(O,'m_run',[[]],#process_info{method= <<"run"/utf8>>},Cog,[O,DC| Stack]),
                        future:get_blocking(TempFuture, Cog, [O,DC| Stack])
                end end)(),
                T_2;
                false ->             ok
            end;
            false ->         ok
        end
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method signalChanged and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Train.abs:130
 %% src/Train.abs:130
'm_getID'(O=#object{class=class_Train_TrainImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
         %% src/Train.abs:131--131
        get(O,'id')
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method getID and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
'set'(O=#object{class=class_Train_TrainImpl=C,ref=Ref,cog=Cog},Var,Val)->
    object:set_field_value(O, Var, Val).

'get'(O=#object{class=class_Train_TrainImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Var)->
    object:get_field_value(O,Var).

-record(state,{'id'=null,'state'=null,'station'=null,'driveIn'=null,'start'=null,'s2'=null,'nextSet'=null,'next'=null,'last'=null}).
'init_internal'()->
    #state{}.

 %% src/Train.abs:24
'get_val_internal'(#state{'id'=G},'id')->
    G;
 %% src/Train.abs:26
'get_val_internal'(#state{'state'=G},'state')->
    G;
 %% src/Train.abs:27
'get_val_internal'(#state{'station'=G},'station')->
    G;
 %% src/Train.abs:28
'get_val_internal'(#state{'driveIn'=G},'driveIn')->
    G;
 %% src/Train.abs:29
'get_val_internal'(#state{'start'=G},'start')->
    G;
 %% src/Train.abs:30
'get_val_internal'(#state{'s2'=G},'s2')->
    G;
 %% src/Train.abs:31
'get_val_internal'(#state{'nextSet'=G},'nextSet')->
    G;
 %% src/Train.abs:33
'get_val_internal'(#state{'next'=G},'next')->
    G;
 %% src/Train.abs:34
'get_val_internal'(#state{'last'=G},'last')->
    G;
'get_val_internal'(_,_)->
    %% Invalid return value; handled by HTTP API when querying for non-existant field.
    %% Will never occur in generated code.
    none.

 %% src/Train.abs:24
'set_val_internal'(S,'id',V)->
    S#state{'id'=V};
 %% src/Train.abs:26
'set_val_internal'(S,'state',V)->
    S#state{'state'=V};
 %% src/Train.abs:27
'set_val_internal'(S,'station',V)->
    S#state{'station'=V};
 %% src/Train.abs:28
'set_val_internal'(S,'driveIn',V)->
    S#state{'driveIn'=V};
 %% src/Train.abs:29
'set_val_internal'(S,'start',V)->
    S#state{'start'=V};
 %% src/Train.abs:30
'set_val_internal'(S,'s2',V)->
    S#state{'s2'=V};
 %% src/Train.abs:31
'set_val_internal'(S,'nextSet',V)->
    S#state{'nextSet'=V};
 %% src/Train.abs:33
'set_val_internal'(S,'next',V)->
    S#state{'next'=V};
 %% src/Train.abs:34
'set_val_internal'(S,'last',V)->
    S#state{'last'=V}.

'get_state_for_modelapi'(S)->
    [
        { 'id', S#state.'id' }
        , { 'state', S#state.'state' }
        , { 'station', S#state.'station' }
        , { 'driveIn', S#state.'driveIn' }
        , { 'start', S#state.'start' }
        , { 's2', S#state.'s2' }
        , { 'nextSet', S#state.'nextSet' }
        , { 'next', S#state.'next' }
        , { 'last', S#state.'last' }
    ].
