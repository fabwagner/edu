-module(class_Station_StationImpl).
-include_lib("../include/abs_types.hrl").
-behaviour(object).
-export([get_val_internal/2,set_val_internal/3,init_internal/0,get_state_for_modelapi/1]).
-compile(export_all).

exported() -> #{  }.

'init'(O=#object{class=class_Station_StationImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},[P_id,P_size,P_name,Stack])->
    put(vars, #{}),
    set(O,'id',P_id),
    set(O,'size',P_size),
    set(O,'name',P_name),
     %% src/Station.abs:25--25
    set(O,'nTrains',0),
     %% src/Station.abs:26--26
    set(O,'train',null),
     %% src/Station.abs:27--27
    set(O,'track',null),
     %% src/Station.abs:29--29
    set(O,'pre',[]),
     %% src/Station.abs:30--30
    set(O,'stations',[]),
     %% src/Station.abs:32--32
    set(O,'constructed',false),
     %% src/Station.abs:33--33
    set(O,'blocked',m_ABS_StdLib_funs:f_set(Cog,[],[O,DC| Stack])),
     %% src/Station.abs:34--34
    set(O,'waitFor',m_ABS_StdLib_funs:f_map(Cog,[],[O,DC| Stack])),
     %% src/Station.abs:35--35
    set(O,'trainDriveOut',m_ABS_StdLib_funs:f_map(Cog,[],[O,DC| Stack])),
    O.
 %% src/Station.abs:37
 %% src/Station.abs:37
'm_register'(O=#object{class=class_Station_StationImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_tr_0,Stack)->
    put(vars, #{ 'this' => O,
 'tr' => V_tr_0 }),
    try
         %% src/Station.abs:38--38
        put(vars, (get(vars))#{'iid' => (fun() -> case maps:get('tr', get(vars)) of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_getID'(maps:get('tr', get(vars)),[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(maps:get('tr', get(vars)),'m_getID',[[]],#process_info{method= <<"getID"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)()}),
         %% src/Station.abs:39--39
        T_1 = builtin:println(Cog,iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([<<"-> ["/utf8>>, get(O,'name')]), <<"].register("/utf8>>]), builtin:toString(Cog,maps:get('iid', get(vars)))]), <<")"/utf8>>])),
        T_1,
         %% src/Station.abs:41--41
        put(vars, (get(vars))#{'retVal' => false}),
         %% src/Station.abs:42--42
        case cmp:lt(get(O,'nTrains'),get(O,'size')) of
            true ->  %% src/Station.abs:43--43
            set(O,'nTrains',(get(O,'nTrains') + 1) ),
             %% src/Station.abs:44--44
            put(vars, (get(vars))#{'retVal' := true});
            false ->         ok
        end,
         %% src/Station.abs:47--47
        maps:get('retVal', get(vars))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method register and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Station.abs:51
 %% src/Station.abs:51
'm_anbieten'(O=#object{class=class_Station_StationImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_tr_0,V_fr_0,Stack)->
    put(vars, #{ 'this' => O,
 'tr' => V_tr_0,
 'fr' => V_fr_0 }),
    try
         %% src/Station.abs:52--52
        put(vars, (get(vars))#{'iid' => (fun() -> case maps:get('tr', get(vars)) of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_getID'(maps:get('tr', get(vars)),[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(maps:get('tr', get(vars)),'m_getID',[[]],#process_info{method= <<"getID"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)()}),
         %% src/Station.abs:53--53
        put(vars, (get(vars))#{'na' => (fun() -> case maps:get('fr', get(vars)) of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_getName'(maps:get('fr', get(vars)),[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(maps:get('fr', get(vars)),'m_getName',[[]],#process_info{method= <<"getName"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)()}),
         %% src/Station.abs:54--54
        T_1 = builtin:println(Cog,iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([<<"-> ["/utf8>>, get(O,'name')]), <<"].anbieten("/utf8>>]), builtin:toString(Cog,maps:get('iid', get(vars)))]), <<", "/utf8>>]), maps:get('na', get(vars))]), <<")"/utf8>>])),
        T_1,
         %% src/Station.abs:56--56
        put(vars, (get(vars))#{'retVal' => false}),
         %% src/Station.abs:57--57
        case not (m_ABS_StdLib_funs:f_contains(Cog,get(O,'blocked'),maps:get('fr', get(vars)),[O,DC| Stack])) of
            true ->  %% src/Station.abs:59--59
            set(O,'blocked',m_ABS_StdLib_funs:f_insertElement(Cog,get(O,'blocked'),maps:get('fr', get(vars)),[O,DC| Stack])),
             %% src/Station.abs:60--60
            T_2 = builtin:println(Cog,<<"gegenfahrschutz activated"/utf8>>),
            T_2,
             %% src/Station.abs:63--63
            put(vars, (get(vars))#{'p' => { dataPair,maps:get('fr', get(vars)),maps:get('tr', get(vars))}}),
             %% src/Station.abs:64--64
            set(O,'waitFor',m_ABS_StdLib_funs:f_insert(Cog,get(O,'waitFor'),maps:get('p', get(vars)),[O,DC| Stack])),
             %% src/Station.abs:65--65
            put(vars, (get(vars))#{'retVal' := true});
            false ->         ok
        end,
         %% src/Station.abs:67--67
        maps:get('retVal', get(vars))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method anbieten and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Station.abs:70
 %% src/Station.abs:70
'm_rueckmeldung'(O=#object{class=class_Station_StationImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_fr_0,Stack)->
    put(vars, #{ 'this' => O,
 'fr' => V_fr_0 }),
    try
         %% src/Station.abs:71--71
        T_1 = builtin:println(Cog,iolist_to_binary([iolist_to_binary([<<"-> ["/utf8>>, get(O,'name')]), <<"].rueckmeldung()"/utf8>>])),
        T_1
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method rueckmeldung and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Station.abs:77
 %% src/Station.abs:77
'm_askDriveOut'(O=#object{class=class_Station_StationImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_tr_0,V_dir_0,Stack)->
    put(vars, #{ 'this' => O,
 'tr' => V_tr_0,
 'dir' => V_dir_0 }),
    try
         %% src/Station.abs:78--78
        put(vars, (get(vars))#{'iid' => (fun() -> case maps:get('tr', get(vars)) of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_getID'(maps:get('tr', get(vars)),[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(maps:get('tr', get(vars)),'m_getID',[[]],#process_info{method= <<"getID"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)()}),
         %% src/Station.abs:79--79
        T_1 = builtin:println(Cog,iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([<<"-> ["/utf8>>, get(O,'name')]), <<"].askDriveOut("/utf8>>]), builtin:toString(Cog,maps:get('iid', get(vars)))]), <<", "/utf8>>]), builtin:toString(Cog,maps:get('dir', get(vars)))]), <<")"/utf8>>])),
        T_1,
         %% src/Station.abs:81--81
        put(vars, (get(vars))#{'tmp2004952636' => future:start(m_ABS_StdLib_funs:f_nth(Cog,get(O,'stations'),maps:get('dir', get(vars)),[O,DC| Stack]),'m_anbieten',[maps:get('tr', get(vars)),O,[]],#process_info{method= <<"anbieten"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack])}),
         %% src/Station.abs:81--81
        future:await(maps:get('tmp2004952636', get(vars)), Cog, [O,DC| Stack]),
        ok,
         %% src/Station.abs:81--81
        put(vars, (get(vars))#{'answer' => future:get_blocking(maps:get('tmp2004952636', get(vars)), Cog, [O,DC| Stack])}),
         %% src/Station.abs:82--82
        case maps:get('answer', get(vars)) of
            true ->  %% src/Station.abs:83--83
            T_2 = builtin:println(Cog,<<"     ->annehmen"/utf8>>),
            T_2,
             %% src/Station.abs:84--84
            set(O,'nTrains',(get(O,'nTrains') - 1) ),
             %% src/Station.abs:85--85
            put(vars, (get(vars))#{'t' => m_ABS_StdLib_funs:f_nth(Cog,get(O,'pre'),maps:get('dir', get(vars)),[O,DC| Stack])}),
             %% src/Station.abs:86--86
            T_3 = (fun() -> case maps:get('t', get(vars)) of
                null -> throw(dataNullPointerException);
                #object{ref=ObjRef,class=T,cog=Cog} ->
                    case is_process_alive(ObjRef) of
                        true ->
                            Vars=get(vars),
                            Result=T:'m_registerDriveOut'(maps:get('t', get(vars)),maps:get('tr', get(vars)),[O,DC| Stack]),
                            put(vars, Vars),
                            Result;
                        false -> throw(dataObjectDeadException)
                    end;
                _ ->
                    TempFuture = future:start(maps:get('t', get(vars)),'m_registerDriveOut',[maps:get('tr', get(vars)),[]],#process_info{method= <<"registerDriveOut"/utf8>>},Cog,[O,DC| Stack]),
                    future:get_blocking(TempFuture, Cog, [O,DC| Stack])
            end end)(),
            T_3,
             %% src/Station.abs:87--87
            T_4 = (fun() -> case maps:get('tr', get(vars)) of
                null -> throw(dataNullPointerException);
                #object{ref=ObjRef,class=T,cog=Cog} ->
                    case is_process_alive(ObjRef) of
                        true ->
                            Vars=get(vars),
                            Result=T:'m_setNext'(maps:get('tr', get(vars)),maps:get('t', get(vars)),[O,DC| Stack]),
                            put(vars, Vars),
                            Result;
                        false -> throw(dataObjectDeadException)
                    end;
                _ ->
                    TempFuture = future:start(maps:get('tr', get(vars)),'m_setNext',[maps:get('t', get(vars)),[]],#process_info{method= <<"setNext"/utf8>>},Cog,[O,DC| Stack]),
                    future:get_blocking(TempFuture, Cog, [O,DC| Stack])
            end end)(),
            T_4,
             %% src/Station.abs:88--88
            T_5 = (fun() -> case maps:get('tr', get(vars)) of
                null -> throw(dataNullPointerException);
                #object{ref=ObjRef,class=T,cog=Cog} ->
                    case is_process_alive(ObjRef) of
                        true ->
                            Vars=get(vars),
                            Result=T:'m_drive_out'(maps:get('tr', get(vars)),[O,DC| Stack]),
                            put(vars, Vars),
                            Result;
                        false -> throw(dataObjectDeadException)
                    end;
                _ ->
                    TempFuture = future:start(maps:get('tr', get(vars)),'m_drive_out',[[]],#process_info{method= <<"drive_out"/utf8>>},Cog,[O,DC| Stack]),
                    future:get_blocking(TempFuture, Cog, [O,DC| Stack])
            end end)(),
            T_5,
             %% src/Station.abs:89--89
            T_6 = future:start(maps:get('t', get(vars)),'m_forceSignal',[0,dataGREEN,[]],#process_info{method= <<"forceSignal"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack]),
            T_6;
            false ->         ok
        end
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method askDriveOut and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Station.abs:93
 %% src/Station.abs:93
'm_askDriveIn'(O=#object{class=class_Station_StationImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_tr_0,Stack)->
    put(vars, #{ 'this' => O,
 'tr' => V_tr_0 }),
    try
         %% src/Station.abs:94--94
        put(vars, (get(vars))#{'iid' => (fun() -> case maps:get('tr', get(vars)) of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_getID'(maps:get('tr', get(vars)),[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(maps:get('tr', get(vars)),'m_getID',[[]],#process_info{method= <<"getID"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)()}),
         %% src/Station.abs:95--95
        T_1 = builtin:println(Cog,iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([<<"-> ["/utf8>>, get(O,'name')]), <<"].askDriveIn("/utf8>>]), builtin:toString(Cog,maps:get('iid', get(vars)))]), <<")"/utf8>>])),
        T_1,
         %% src/Station.abs:97--97
        put(vars, (get(vars))#{'retVal' => false}),
         %% src/Station.abs:98--98
        case cmp:lt(get(O,'nTrains'),get(O,'size')) of
            true ->  %% src/Station.abs:99--99
            set(O,'nTrains',(get(O,'nTrains') + 1) ),
             %% src/Station.abs:100--100
            put(vars, (get(vars))#{'retVal' := true});
            false ->         ok
        end,
         %% src/Station.abs:102--102
        maps:get('retVal', get(vars))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method askDriveIn and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Station.abs:105
 %% src/Station.abs:105
'm_getID'(O=#object{class=class_Station_StationImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
         %% src/Station.abs:106--106
        get(O,'id')
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method getID and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Station.abs:109
 %% src/Station.abs:109
'm_driveIn'(O=#object{class=class_Station_StationImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_tr_0,V_fr_0,Stack)->
    put(vars, #{ 'this' => O,
 'tr' => V_tr_0,
 'fr' => V_fr_0 }),
    try
         %% src/Station.abs:110--110
        put(vars, (get(vars))#{'iid' => 1}),
         %% src/Station.abs:111--111
        put(vars, (get(vars))#{'na' => (fun() -> case maps:get('fr', get(vars)) of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_getName'(maps:get('fr', get(vars)),[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(maps:get('fr', get(vars)),'m_getName',[[]],#process_info{method= <<"getName"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)()}),
         %% src/Station.abs:112--112
        T_1 = builtin:println(Cog,iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([<<"-> ["/utf8>>, get(O,'name')]), <<"].driveIn("/utf8>>]), builtin:toString(Cog,maps:get('iid', get(vars)))]), <<", "/utf8>>]), maps:get('na', get(vars))]), <<")"/utf8>>])),
        T_1,
         %% src/Station.abs:114--114
        T_2 = future:start(maps:get('fr', get(vars)),'m_rueckmeldung',[O,[]],#process_info{method= <<"rueckmeldung"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack]),
        T_2,
         %% src/Station.abs:115--115
        T_3 = (fun() -> case maps:get('tr', get(vars)) of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_drive_in'(maps:get('tr', get(vars)),O,[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(maps:get('tr', get(vars)),'m_drive_in',[O,[]],#process_info{method= <<"drive_in"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)(),
        T_3
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method driveIn and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Station.abs:118
 %% src/Station.abs:118
'm_construct'(O=#object{class=class_Station_StationImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_pre_0,V_stations_0,Stack)->
    put(vars, #{ 'this' => O,
 'pre' => V_pre_0,
 'stations' => V_stations_0 }),
    try
         %% src/Station.abs:119--119
        T_1 = builtin:println(Cog,iolist_to_binary([iolist_to_binary([<<"-> ["/utf8>>, get(O,'name')]), <<"].construct(...)"/utf8>>])),
        T_1,
         %% src/Station.abs:121--121
        case (not (get(O,'constructed'))) and (cmp:eq(m_ABS_StdLib_funs:f_length(Cog,maps:get('pre', get(vars)),[O,DC| Stack]),m_ABS_StdLib_funs:f_length(Cog,maps:get('stations', get(vars)),[O,DC| Stack]))) of
            true ->  %% src/Station.abs:122--122
            put(vars, (get(vars))#{'str' => iolist_to_binary([<<"Station "/utf8>>, get(O,'name')])}),
             %% src/Station.abs:123--123
            set(O,'track',object:new(cog:start(DC),class_TrackElement_TrackElementStation,[maps:get('str', get(vars)),[]],Cog,[O,DC| Stack])),
             %% src/Station.abs:124--124
            set(O,'stations',maps:get('stations', get(vars))),
             %% src/Station.abs:125--125
            put(vars, (get(vars))#{'i' => 0}),
             %% src/Station.abs:126--126
            []=(fun Loop ([])->
                case cmp:lt(maps:get('i', get(vars)),m_ABS_StdLib_funs:f_length(Cog,maps:get('pre', get(vars)),[O,DC| Stack])) of
                false -> [];
                true -> receive
                        {stop_world, CogRef} ->
                            cog:process_is_blocked_for_gc(Cog, self()),
                            cog:process_is_runnable(Cog,self()),
                            task:wait_for_token(Cog,[O,DC| Stack]);
                        die_prematurely ->
                            task:send_notifications(killed_by_the_clock),
                            exit(killed_by_the_clock)
                    after 0 -> ok end,
                     %% src/Station.abs:127--127
                    put(vars, (get(vars))#{'str' := iolist_to_binary([iolist_to_binary([iolist_to_binary([<<"Pre from: "/utf8>>, get(O,'name')]), <<" "/utf8>>]), builtin:toString(Cog,maps:get('i', get(vars)))])}),
                     %% src/Station.abs:128--128
                    put(vars, (get(vars))#{'t' => object:new(cog:start(DC),class_TrackElement_TrackElementPreStation,[maps:get('str', get(vars)),[]],Cog,[O,DC| Stack])}),
                     %% src/Station.abs:129--129
                    put(vars, (get(vars))#{'tmp505693686' => future:start(maps:get('t', get(vars)),'m_construct',[[O, m_ABS_StdLib_funs:f_nth(Cog,maps:get('pre', get(vars)),maps:get('i', get(vars)),[O,DC| Stack])],[O],[]],#process_info{method= <<"construct"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack])}),
                     %% src/Station.abs:129--129
                    future:await(maps:get('tmp505693686', get(vars)), Cog, [O,DC| Stack]),
                    ok,
                     %% src/Station.abs:131--131
                    put(vars, (get(vars))#{'pt' => m_ABS_StdLib_funs:f_nth(Cog,maps:get('pre', get(vars)),maps:get('i', get(vars)),[O,DC| Stack])}),
                     %% src/Station.abs:132--132
                    T_2 = (fun() -> case maps:get('pt', get(vars)) of
                        null -> throw(dataNullPointerException);
                        #object{ref=ObjRef,class=T,cog=Cog} ->
                            case is_process_alive(ObjRef) of
                                true ->
                                    Vars=get(vars),
                                    Result=T:'m_forceSet'(maps:get('pt', get(vars)),maps:get('t', get(vars)),-1,[O,DC| Stack]),
                                    put(vars, Vars),
                                    Result;
                                false -> throw(dataObjectDeadException)
                            end;
                        _ ->
                            TempFuture = future:start(maps:get('pt', get(vars)),'m_forceSet',[maps:get('t', get(vars)),-1,[]],#process_info{method= <<"forceSet"/utf8>>},Cog,[O,DC| Stack]),
                            future:get_blocking(TempFuture, Cog, [O,DC| Stack])
                    end end)(),
                    T_2,
                     %% src/Station.abs:134--134
                    put(vars, (get(vars))#{'lot' => [maps:get('t', get(vars))]}),
                     %% src/Station.abs:135--135
                    set(O,'pre',m_ABS_StdLib_funs:f_concatenate(Cog,get(O,'pre'),maps:get('lot', get(vars)),[O,DC| Stack])),
                     %% src/Station.abs:136--136
                    put(vars, (get(vars))#{'i' := (maps:get('i', get(vars)) + 1) }),
                Loop([])  end end)
            ([]),
             %% src/Station.abs:139--139
            put(vars, (get(vars))#{'tmp1186663391' => future:start(get(O,'track'),'m_construct',[maps:get('pre', get(vars)),[],[]],#process_info{method= <<"construct"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack])}),
             %% src/Station.abs:139--139
            future:await(maps:get('tmp1186663391', get(vars)), Cog, [O,DC| Stack]),
            ok,
             %% src/Station.abs:141--141
            set(O,'constructed',true);
            false ->         ok
        end,
         %% src/Station.abs:143--143
        true
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method construct and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Station.abs:148
 %% src/Station.abs:148
'm_forceSet'(O=#object{class=class_Station_StationImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_t_0,V_id_0,Stack)->
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
 %% src/Station.abs:152
 %% src/Station.abs:152
'm_registerDriveOut'(O=#object{class=class_Station_StationImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_tr_0,Stack)->
    put(vars, #{ 'this' => O,
 'tr' => V_tr_0 }),
    try
         %% src/Station.abs:153--153
        T_1 = (fun() -> case get(O,'track') of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_registerDriveOut'(get(O,'track'),maps:get('tr', get(vars)),[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(get(O,'track'),'m_registerDriveOut',[maps:get('tr', get(vars)),[]],#process_info{method= <<"registerDriveOut"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)(),
        T_1
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method registerDriveOut and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Station.abs:156
 %% src/Station.abs:156
'm_registerTrain'(O=#object{class=class_Station_StationImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_tr_0,V_p_0,Stack)->
    put(vars, #{ 'this' => O,
 'tr' => V_tr_0,
 'p' => V_p_0 }),
    try
         %% src/Station.abs:157--157
        put(vars, (get(vars))#{'retVal' => (fun() -> case get(O,'track') of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_registerTrain'(get(O,'track'),maps:get('tr', get(vars)),maps:get('p', get(vars)),[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(get(O,'track'),'m_registerTrain',[maps:get('tr', get(vars)),maps:get('p', get(vars)),[]],#process_info{method= <<"registerTrain"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)()}),
         %% src/Station.abs:158--158
        maps:get('retVal', get(vars))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method registerTrain and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Station.abs:161
 %% src/Station.abs:161
'm_forceSignal'(O=#object{class=class_Station_StationImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_id_0,V_s_0,Stack)->
    put(vars, #{ 'this' => O,
 'id' => V_id_0,
 's' => V_s_0 }),
    try
         %% src/Station.abs:162--162
        T_1 = future:start(get(O,'track'),'m_forceSignal',[maps:get('id', get(vars)),maps:get('s', get(vars)),[]],#process_info{method= <<"forceSignal"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack]),
        T_1
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method forceSignal and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Station.abs:165
 %% src/Station.abs:165
'm_printName'(O=#object{class=class_Station_StationImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
         %% src/Station.abs:166--166
        T_1 = builtin:println(Cog,<<"TrackElement Station"/utf8>>),
        T_1,
         %% src/Station.abs:167--167
        T_2 = builtin:println(Cog,get(O,'name')),
        T_2
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method printName and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Station.abs:170
 %% src/Station.abs:170
'm_getName'(O=#object{class=class_Station_StationImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
         %% src/Station.abs:171--171
        get(O,'name')
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method getName and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Station.abs:173
 %% src/Station.abs:173
'm_getType'(O=#object{class=class_Station_StationImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
         %% src/Station.abs:174--174
        dataStation
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method getType and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Station.abs:177
 %% src/Station.abs:177
'm_getSignal'(O=#object{class=class_Station_StationImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_id_0,Stack)->
    put(vars, #{ 'this' => O,
 'id' => V_id_0 }),
    try
         %% src/Station.abs:178--178
        put(vars, (get(vars))#{'retVal' => (fun() -> case get(O,'track') of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_getSignal'(get(O,'track'),maps:get('id', get(vars)),[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(get(O,'track'),'m_getSignal',[maps:get('id', get(vars)),[]],#process_info{method= <<"getSignal"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)()}),
         %% src/Station.abs:179--179
        maps:get('retVal', get(vars))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method getSignal and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Station.abs:182
 %% src/Station.abs:182
'm_getTrackElement'(O=#object{class=class_Station_StationImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_id_0,Stack)->
    put(vars, #{ 'this' => O,
 'id' => V_id_0 }),
    try
         %% src/Station.abs:183--183
        put(vars, (get(vars))#{'retVal' => (fun() -> case get(O,'track') of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_getTrackElement'(get(O,'track'),maps:get('id', get(vars)),[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(get(O,'track'),'m_getTrackElement',[maps:get('id', get(vars)),[]],#process_info{method= <<"getTrackElement"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)()}),
         %% src/Station.abs:184--184
        maps:get('retVal', get(vars))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method getTrackElement and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Station.abs:186
 %% src/Station.abs:186
'm_occupy'(O=#object{class=class_Station_StationImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_tr_0,V_p_0,Stack)->
    put(vars, #{ 'this' => O,
 'tr' => V_tr_0,
 'p' => V_p_0 }),
    try
         %% src/Station.abs:187--187
        put(vars, (get(vars))#{'iid' => (fun() -> case maps:get('tr', get(vars)) of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_getID'(maps:get('tr', get(vars)),[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(maps:get('tr', get(vars)),'m_getID',[[]],#process_info{method= <<"getID"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)()}),
         %% src/Station.abs:188--188
        put(vars, (get(vars))#{'na' => (fun() -> case maps:get('p', get(vars)) of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_getName'(maps:get('p', get(vars)),[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(maps:get('p', get(vars)),'m_getName',[[]],#process_info{method= <<"getName"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)()}),
         %% src/Station.abs:189--189
        T_1 = builtin:println(Cog,iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([<<"-> ["/utf8>>, get(O,'name')]), <<"].occupy("/utf8>>]), builtin:toString(Cog,maps:get('iid', get(vars)))]), <<", "/utf8>>]), maps:get('na', get(vars))]), <<")"/utf8>>])),
        T_1,
         %% src/Station.abs:191--191
        put(vars, (get(vars))#{'retVal' => false}),
         %% src/Station.abs:192--192
        put(vars, (get(vars))#{'dir' => m_ABS_StdLib_funs:f_lookup(Cog,get(O,'trainDriveOut'),maps:get('tr', get(vars)),[O,DC| Stack])}),
         %% src/Station.abs:193--193
        case m_ABS_StdLib_funs:f_isJust(Cog,maps:get('dir', get(vars)),[O,DC| Stack]) of
            true ->  %% src/Station.abs:194--194
            T_2 = (fun() -> case maps:get('tr', get(vars)) of
                null -> throw(dataNullPointerException);
                #object{ref=ObjRef,class=T,cog=Cog} ->
                    case is_process_alive(ObjRef) of
                        true ->
                            Vars=get(vars),
                            Result=T:'m_setNext'(maps:get('tr', get(vars)),m_ABS_StdLib_funs:f_nth(Cog,get(O,'pre'),m_ABS_StdLib_funs:f_fromJust(Cog,maps:get('dir', get(vars)),[O,DC| Stack]),[O,DC| Stack]),[O,DC| Stack]),
                            put(vars, Vars),
                            Result;
                        false -> throw(dataObjectDeadException)
                    end;
                _ ->
                    TempFuture = future:start(maps:get('tr', get(vars)),'m_setNext',[m_ABS_StdLib_funs:f_nth(Cog,get(O,'pre'),m_ABS_StdLib_funs:f_fromJust(Cog,maps:get('dir', get(vars)),[O,DC| Stack]),[O,DC| Stack]),[]],#process_info{method= <<"setNext"/utf8>>},Cog,[O,DC| Stack]),
                    future:get_blocking(TempFuture, Cog, [O,DC| Stack])
            end end)(),
            T_2,
             %% src/Station.abs:195--195
            put(vars, (get(vars))#{'retVal' := true});
            false ->         ok
        end,
         %% src/Station.abs:197--197
        maps:get('retVal', get(vars))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method occupy and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/Station.abs:201
 %% src/Station.abs:201
'm_drive_in'(O=#object{class=class_Station_StationImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_tr_0,Stack)->
    put(vars, #{ 'this' => O,
 'tr' => V_tr_0 }),
    try
        ok
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method drive_in and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
'set'(O=#object{class=class_Station_StationImpl=C,ref=Ref,cog=Cog},Var,Val)->
    object:set_field_value(O, Var, Val).

'get'(O=#object{class=class_Station_StationImpl=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Var)->
    object:get_field_value(O,Var).

-record(state,{'id'=null,'size'=null,'name'=null,'nTrains'=null,'train'=null,'track'=null,'pre'=null,'stations'=null,'constructed'=null,'blocked'=null,'waitFor'=null,'trainDriveOut'=null}).
'init_internal'()->
    #state{}.

 %% src/Station.abs:23
'get_val_internal'(#state{'id'=G},'id')->
    G;
 %% src/Station.abs:23
'get_val_internal'(#state{'size'=G},'size')->
    G;
 %% src/Station.abs:23
'get_val_internal'(#state{'name'=G},'name')->
    G;
 %% src/Station.abs:25
'get_val_internal'(#state{'nTrains'=G},'nTrains')->
    G;
 %% src/Station.abs:26
'get_val_internal'(#state{'train'=G},'train')->
    G;
 %% src/Station.abs:27
'get_val_internal'(#state{'track'=G},'track')->
    G;
 %% src/Station.abs:29
'get_val_internal'(#state{'pre'=G},'pre')->
    G;
 %% src/Station.abs:30
'get_val_internal'(#state{'stations'=G},'stations')->
    G;
 %% src/Station.abs:32
'get_val_internal'(#state{'constructed'=G},'constructed')->
    G;
 %% src/Station.abs:33
'get_val_internal'(#state{'blocked'=G},'blocked')->
    G;
 %% src/Station.abs:34
'get_val_internal'(#state{'waitFor'=G},'waitFor')->
    G;
 %% src/Station.abs:35
'get_val_internal'(#state{'trainDriveOut'=G},'trainDriveOut')->
    G;
'get_val_internal'(_,_)->
    %% Invalid return value; handled by HTTP API when querying for non-existant field.
    %% Will never occur in generated code.
    none.

 %% src/Station.abs:23
'set_val_internal'(S,'id',V)->
    S#state{'id'=V};
 %% src/Station.abs:23
'set_val_internal'(S,'size',V)->
    S#state{'size'=V};
 %% src/Station.abs:23
'set_val_internal'(S,'name',V)->
    S#state{'name'=V};
 %% src/Station.abs:25
'set_val_internal'(S,'nTrains',V)->
    S#state{'nTrains'=V};
 %% src/Station.abs:26
'set_val_internal'(S,'train',V)->
    S#state{'train'=V};
 %% src/Station.abs:27
'set_val_internal'(S,'track',V)->
    S#state{'track'=V};
 %% src/Station.abs:29
'set_val_internal'(S,'pre',V)->
    S#state{'pre'=V};
 %% src/Station.abs:30
'set_val_internal'(S,'stations',V)->
    S#state{'stations'=V};
 %% src/Station.abs:32
'set_val_internal'(S,'constructed',V)->
    S#state{'constructed'=V};
 %% src/Station.abs:33
'set_val_internal'(S,'blocked',V)->
    S#state{'blocked'=V};
 %% src/Station.abs:34
'set_val_internal'(S,'waitFor',V)->
    S#state{'waitFor'=V};
 %% src/Station.abs:35
'set_val_internal'(S,'trainDriveOut',V)->
    S#state{'trainDriveOut'=V}.

'get_state_for_modelapi'(S)->
    [
        { 'id', S#state.'id' }
        , { 'size', S#state.'size' }
        , { 'name', S#state.'name' }
        , { 'nTrains', S#state.'nTrains' }
        , { 'train', S#state.'train' }
        , { 'track', S#state.'track' }
        , { 'pre', S#state.'pre' }
        , { 'stations', S#state.'stations' }
        , { 'constructed', S#state.'constructed' }
        , { 'blocked', S#state.'blocked' }
        , { 'waitFor', S#state.'waitFor' }
        , { 'trainDriveOut', S#state.'trainDriveOut' }
    ].
