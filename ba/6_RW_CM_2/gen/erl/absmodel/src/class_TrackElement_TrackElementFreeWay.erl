-module(class_TrackElement_TrackElementFreeWay).
-include_lib("../include/abs_types.hrl").
-behaviour(object).
-export([get_val_internal/2,set_val_internal/3,init_internal/0,get_state_for_modelapi/1]).
-compile(export_all).

exported() -> #{  }.

'init'(O=#object{class=class_TrackElement_TrackElementFreeWay=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},[P_name,Stack])->
    put(vars, #{}),
    set(O,'name',P_name),
     %% src/TrackElement.abs:31--31
    set(O,'train',null),
     %% src/TrackElement.abs:32--32
    set(O,'s1',null),
     %% src/TrackElement.abs:33--33
    set(O,'s2',null),
     %% src/TrackElement.abs:34--34
    set(O,'pre',[]),
     %% src/TrackElement.abs:35--35
    set(O,'pre2',m_ABS_StdLib_funs:f_map(Cog,[],[O,DC| Stack])),
     %% src/TrackElement.abs:36--36
    set(O,'gegenfahrschutz',false),
     %% src/TrackElement.abs:37--37
    set(O,'occupied',false),
    O.
 %% src/TrackElement.abs:39
 %% src/TrackElement.abs:39
'm_printName'(O=#object{class=class_TrackElement_TrackElementFreeWay=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
         %% src/TrackElement.abs:40--40
        T_1 = builtin:println(Cog,<<"TrackElement Freeway"/utf8>>),
        T_1,
         %% src/TrackElement.abs:41--41
        T_2 = builtin:println(Cog,get(O,'name')),
        T_2
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method printName and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:44
 %% src/TrackElement.abs:44
'm_getSignal'(O=#object{class=class_TrackElement_TrackElementFreeWay=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_id_0,Stack)->
    put(vars, #{ 'this' => O,
 'id' => V_id_0 }),
    try
         %% src/TrackElement.abs:45--45
        put(vars, (get(vars))#{'retVal' => null}),
         %% src/TrackElement.abs:46--46
        case cmp:eq(maps:get('id', get(vars)),0) of
            true ->  %% src/TrackElement.abs:47--47
            put(vars, (get(vars))#{'retVal' := get(O,'s1')});
            false ->          %% src/TrackElement.abs:49--49
        put(vars, (get(vars))#{'retVal' := get(O,'s2')})
        end,
         %% src/TrackElement.abs:50--50
        maps:get('retVal', get(vars))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method getSignal and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:53
 %% src/TrackElement.abs:53
'm_getTrackElement'(O=#object{class=class_TrackElement_TrackElementFreeWay=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_id_0,Stack)->
    put(vars, #{ 'this' => O,
 'id' => V_id_0 }),
    try
         %% src/TrackElement.abs:54--54
        put(vars, (get(vars))#{'retVal' => m_ABS_StdLib_funs:f_nth(Cog,get(O,'pre'),maps:get('id', get(vars)),[O,DC| Stack])}),
         %% src/TrackElement.abs:55--55
        maps:get('retVal', get(vars))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method getTrackElement and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:58
 %% src/TrackElement.abs:58
'm_getType'(O=#object{class=class_TrackElement_TrackElementFreeWay=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
         %% src/TrackElement.abs:59--59
        dataFreeWay
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method getType and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:62
 %% src/TrackElement.abs:62
'm_getName'(O=#object{class=class_TrackElement_TrackElementFreeWay=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
         %% src/TrackElement.abs:63--63
        get(O,'name')
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method getName and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:66
 %% src/TrackElement.abs:66
'm_forceSet'(O=#object{class=class_TrackElement_TrackElementFreeWay=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_t_0,V_id_0,Stack)->
    put(vars, #{ 'this' => O,
 't' => V_t_0,
 'id' => V_id_0 }),
    try
         %% src/TrackElement.abs:67--67
        put(vars, (get(vars))#{'na' => (fun() -> case maps:get('t', get(vars)) of
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
         %% src/TrackElement.abs:68--68
        T_1 = builtin:println(Cog,iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([<<"-> ["/utf8>>, get(O,'name')]), <<"].forceSet("/utf8>>]), maps:get('na', get(vars))]), <<", "/utf8>>]), builtin:toString(Cog,maps:get('id', get(vars)))]), <<")"/utf8>>])),
        T_1,
         %% src/TrackElement.abs:70--70
        case cmp:eq(maps:get('id', get(vars)),-1) of
            true ->  %% src/TrackElement.abs:71--71
            put(vars, (get(vars))#{'p' => { dataPair,0,maps:get('t', get(vars))}}),
             %% src/TrackElement.abs:72--72
            set(O,'pre2',m_ABS_StdLib_funs:f_insert(Cog,get(O,'pre2'),maps:get('p', get(vars)),[O,DC| Stack]));
            false ->         ok
        end
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method forceSet and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:78
 %% src/TrackElement.abs:78
'm_registerTrain'(O=#object{class=class_TrackElement_TrackElementFreeWay=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_tr_0,V_p_0,Stack)->
    put(vars, #{ 'this' => O,
 'tr' => V_tr_0,
 'p' => V_p_0 }),
    try
         %% src/TrackElement.abs:79--79
        T_1 = builtin:println(Cog,iolist_to_binary([iolist_to_binary([<<"-> ["/utf8>>, get(O,'name')]), <<"].registerTrain(...)"/utf8>>])),
        T_1,
         %% src/TrackElement.abs:81--81
        put(vars, (get(vars))#{'retVal' => -1}),
         %% src/TrackElement.abs:82--82
        case cmp:eq(maps:get('p', get(vars)),null) of
            true ->  %% src/TrackElement.abs:83--83
            put(vars, (get(vars))#{'t' => m_ABS_StdLib_funs:f_nth(Cog,get(O,'pre'),0,[O,DC| Stack])}),
             %% src/TrackElement.abs:84--84
            put(vars, (get(vars))#{'mt' => m_ABS_StdLib_funs:f_lookup(Cog,get(O,'pre2'),0,[O,DC| Stack])}),
             %% src/TrackElement.abs:85--85
            put(vars, (get(vars))#{'t' := m_ABS_StdLib_funs:f_fromJust(Cog,maps:get('mt', get(vars)),[O,DC| Stack])}),
             %% src/TrackElement.abs:86--86
            put(vars, (get(vars))#{'tmp2014406233' => future:start(maps:get('t', get(vars)),'m_getType',[[]],#process_info{method= <<"getType"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack])}),
             %% src/TrackElement.abs:86--86
            future:await(maps:get('tmp2014406233', get(vars)), Cog, [O,DC| Stack]),
            ok,
             %% src/TrackElement.abs:86--86
            put(vars, (get(vars))#{'tt' => future:get_blocking(maps:get('tmp2014406233', get(vars)), Cog, [O,DC| Stack])}),
             %% src/TrackElement.abs:88--88
            T_2 = builtin:println(Cog,<<"adsd"/utf8>>),
            T_2,
             %% src/TrackElement.abs:89--89
            case cmp:eq(maps:get('tt', get(vars)),dataPre) of
                true ->  %% src/TrackElement.abs:90--90
                T_3 = builtin:println(Cog,<<"	register train on signal 1"/utf8>>),
                T_3,
                 %% src/TrackElement.abs:91--91
                T_4 = (fun() -> case get(O,'s1') of
                    null -> throw(dataNullPointerException);
                    #object{ref=ObjRef,class=T,cog=Cog} ->
                        case is_process_alive(ObjRef) of
                            true ->
                                Vars=get(vars),
                                Result=T:'m_registerTrain'(get(O,'s1'),maps:get('tr', get(vars)),[O,DC| Stack]),
                                put(vars, Vars),
                                Result;
                            false -> throw(dataObjectDeadException)
                        end;
                    _ ->
                        TempFuture = future:start(get(O,'s1'),'m_registerTrain',[maps:get('tr', get(vars)),[]],#process_info{method= <<"registerTrain"/utf8>>},Cog,[O,DC| Stack]),
                        future:get_blocking(TempFuture, Cog, [O,DC| Stack])
                end end)(),
                T_4,
                 %% src/TrackElement.abs:92--92
                put(vars, (get(vars))#{'retVal' := 0});
                false ->              %% src/TrackElement.abs:94--94
            T_3 = (fun() -> case get(O,'s2') of
                null -> throw(dataNullPointerException);
                #object{ref=ObjRef,class=T,cog=Cog} ->
                    case is_process_alive(ObjRef) of
                        true ->
                            Vars=get(vars),
                            Result=T:'m_registerTrain'(get(O,'s2'),maps:get('tr', get(vars)),[O,DC| Stack]),
                            put(vars, Vars),
                            Result;
                        false -> throw(dataObjectDeadException)
                    end;
                _ ->
                    TempFuture = future:start(get(O,'s2'),'m_registerTrain',[maps:get('tr', get(vars)),[]],#process_info{method= <<"registerTrain"/utf8>>},Cog,[O,DC| Stack]),
                    future:get_blocking(TempFuture, Cog, [O,DC| Stack])
            end end)(),
            T_3,
             %% src/TrackElement.abs:95--95
            T_4 = builtin:println(Cog,<<"	register train on signal 2"/utf8>>),
            T_4,
             %% src/TrackElement.abs:96--96
            put(vars, (get(vars))#{'retVal' := 1})
            end;
            false ->          %% src/TrackElement.abs:99--99
        put(vars, (get(vars))#{'mt' => m_ABS_StdLib_funs:f_lookup(Cog,get(O,'pre2'),0,[O,DC| Stack])}),
         %% src/TrackElement.abs:100--100
        put(vars, (get(vars))#{'t' => m_ABS_StdLib_funs:f_fromJust(Cog,maps:get('mt', get(vars)),[O,DC| Stack])}),
         %% src/TrackElement.abs:102--102
        put(vars, (get(vars))#{'mt' := m_ABS_StdLib_funs:f_lookup(Cog,get(O,'pre2'),1,[O,DC| Stack])}),
         %% src/TrackElement.abs:103--103
        put(vars, (get(vars))#{'t2' => m_ABS_StdLib_funs:f_fromJust(Cog,maps:get('mt', get(vars)),[O,DC| Stack])}),
         %% src/TrackElement.abs:105--105
        case cmp:eq(maps:get('t', get(vars)),maps:get('p', get(vars))) of
            true ->  %% src/TrackElement.abs:106--106
            T_2 = builtin:println(Cog,<<"	register train on signal 1"/utf8>>),
            T_2,
             %% src/TrackElement.abs:107--107
            T_3 = (fun() -> case get(O,'s1') of
                null -> throw(dataNullPointerException);
                #object{ref=ObjRef,class=T,cog=Cog} ->
                    case is_process_alive(ObjRef) of
                        true ->
                            Vars=get(vars),
                            Result=T:'m_registerTrain'(get(O,'s1'),maps:get('tr', get(vars)),[O,DC| Stack]),
                            put(vars, Vars),
                            Result;
                        false -> throw(dataObjectDeadException)
                    end;
                _ ->
                    TempFuture = future:start(get(O,'s1'),'m_registerTrain',[maps:get('tr', get(vars)),[]],#process_info{method= <<"registerTrain"/utf8>>},Cog,[O,DC| Stack]),
                    future:get_blocking(TempFuture, Cog, [O,DC| Stack])
            end end)(),
            T_3,
             %% src/TrackElement.abs:108--108
            put(vars, (get(vars))#{'retVal' := 0});
            false ->          %% src/TrackElement.abs:109--109
        case cmp:eq(maps:get('t2', get(vars)),maps:get('p', get(vars))) of
            true ->  %% src/TrackElement.abs:110--110
            T_2 = builtin:println(Cog,<<"	register train on signal 2"/utf8>>),
            T_2,
             %% src/TrackElement.abs:111--111
            T_3 = (fun() -> case get(O,'s2') of
                null -> throw(dataNullPointerException);
                #object{ref=ObjRef,class=T,cog=Cog} ->
                    case is_process_alive(ObjRef) of
                        true ->
                            Vars=get(vars),
                            Result=T:'m_registerTrain'(get(O,'s2'),maps:get('tr', get(vars)),[O,DC| Stack]),
                            put(vars, Vars),
                            Result;
                        false -> throw(dataObjectDeadException)
                    end;
                _ ->
                    TempFuture = future:start(get(O,'s2'),'m_registerTrain',[maps:get('tr', get(vars)),[]],#process_info{method= <<"registerTrain"/utf8>>},Cog,[O,DC| Stack]),
                    future:get_blocking(TempFuture, Cog, [O,DC| Stack])
            end end)(),
            T_3,
             %% src/TrackElement.abs:112--112
            put(vars, (get(vars))#{'retVal' := 1});
            false ->         ok
        end
        end
        end,
         %% src/TrackElement.abs:117--117
        maps:get('retVal', get(vars))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method registerTrain and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:119
 %% src/TrackElement.abs:119
'm_construct'(O=#object{class=class_TrackElement_TrackElementFreeWay=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_pre_0,V_stations_0,Stack)->
    put(vars, #{ 'this' => O,
 'pre' => V_pre_0,
 'stations' => V_stations_0 }),
    try
         %% src/TrackElement.abs:120--120
        T_1 = builtin:println(Cog,iolist_to_binary([iolist_to_binary([<<"-> ["/utf8>>, get(O,'name')]), <<"].construct(...)"/utf8>>])),
        T_1,
         %% src/TrackElement.abs:121--121
        set(O,'s1',object:new(cog:start(DC),class_Signal_SignalFreeWay,[[]],Cog,[O,DC| Stack])),
         %% src/TrackElement.abs:122--122
        set(O,'s2',object:new(cog:start(DC),class_Signal_SignalFreeWay,[[]],Cog,[O,DC| Stack])),
         %% src/TrackElement.abs:124--124
        T_2 = (fun() -> case get(O,'s1') of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_construct'(get(O,'s1'),O,[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(get(O,'s1'),'m_construct',[O,[]],#process_info{method= <<"construct"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)(),
        T_2,
         %% src/TrackElement.abs:125--125
        T_3 = (fun() -> case get(O,'s2') of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_construct'(get(O,'s2'),O,[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(get(O,'s2'),'m_construct',[O,[]],#process_info{method= <<"construct"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)(),
        T_3,
         %% src/TrackElement.abs:126--126
        set(O,'pre',maps:get('pre', get(vars))),
         %% src/TrackElement.abs:127--127
        put(vars, (get(vars))#{'i' => 0}),
         %% src/TrackElement.abs:128--128
        put(vars, (get(vars))#{'s' => m_ABS_StdLib_funs:f_values(Cog,get(O,'pre2'),[O,DC| Stack])}),
         %% src/TrackElement.abs:129--129
        case cmp:gt(m_ABS_StdLib_funs:f_length(Cog,maps:get('s', get(vars)),[O,DC| Stack]),0) of
            true ->  %% src/TrackElement.abs:130--130
            put(vars, (get(vars))#{'i' := m_ABS_StdLib_funs:f_length(Cog,maps:get('s', get(vars)),[O,DC| Stack])});
            false ->         ok
        end,
         %% src/TrackElement.abs:132--132
        []=(fun Loop ([])->
            case not (m_ABS_StdLib_funs:f_isEmpty(Cog,maps:get('pre', get(vars)),[O,DC| Stack])) of
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
                 %% src/TrackElement.abs:133--133
                put(vars, (get(vars))#{'t' => m_ABS_StdLib_funs:f_head(Cog,maps:get('pre', get(vars)),[O,DC| Stack])}),
                 %% src/TrackElement.abs:134--134
                put(vars, (get(vars))#{'tmp860148067' => future:start(maps:get('t', get(vars)),'m_getType',[[]],#process_info{method= <<"getType"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack])}),
                 %% src/TrackElement.abs:134--134
                future:await(maps:get('tmp860148067', get(vars)), Cog, [O,DC| Stack]),
                ok,
                 %% src/TrackElement.abs:134--134
                put(vars, (get(vars))#{'tt' => future:get_blocking(maps:get('tmp860148067', get(vars)), Cog, [O,DC| Stack])}),
                 %% src/TrackElement.abs:135--135
                case cmp:eq(maps:get('tt', get(vars)),dataStation) of
                    true -> ok;
                    false ->                  %% src/TrackElement.abs:138--138
                put(vars, (get(vars))#{'p' => { dataPair,maps:get('i', get(vars)),maps:get('t', get(vars))}}),
                 %% src/TrackElement.abs:139--139
                set(O,'pre2',m_ABS_StdLib_funs:f_insert(Cog,get(O,'pre2'),maps:get('p', get(vars)),[O,DC| Stack])),
                 %% src/TrackElement.abs:140--140
                put(vars, (get(vars))#{'i' := (maps:get('i', get(vars)) + 1) })
                end,
                 %% src/TrackElement.abs:142--142
                put(vars, (get(vars))#{'pre' := m_ABS_StdLib_funs:f_tail(Cog,maps:get('pre', get(vars)),[O,DC| Stack])}),
            Loop([])  end end)
        ([]),
         %% src/TrackElement.abs:144--144
        true
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method construct and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:148
 %% src/TrackElement.abs:148
'm_registerDriveOut'(O=#object{class=class_TrackElement_TrackElementFreeWay=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_tr_0,Stack)->
    put(vars, #{ 'this' => O,
 'tr' => V_tr_0 }),
    try
        ok
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method registerDriveOut and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:151
 %% src/TrackElement.abs:151
'm_forceSignal'(O=#object{class=class_TrackElement_TrackElementFreeWay=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_id_0,V_s_0,Stack)->
    put(vars, #{ 'this' => O,
 'id' => V_id_0,
 's' => V_s_0 }),
    try
         %% src/TrackElement.abs:152--152
        case cmp:eq(maps:get('id', get(vars)),0) of
            true ->  %% src/TrackElement.abs:153--153
            T_1 = (fun() -> case get(O,'s1') of
                null -> throw(dataNullPointerException);
                #object{ref=ObjRef,class=T,cog=Cog} ->
                    case is_process_alive(ObjRef) of
                        true ->
                            Vars=get(vars),
                            Result=T:'m_forceSignal'(get(O,'s1'),maps:get('s', get(vars)),[O,DC| Stack]),
                            put(vars, Vars),
                            Result;
                        false -> throw(dataObjectDeadException)
                    end;
                _ ->
                    TempFuture = future:start(get(O,'s1'),'m_forceSignal',[maps:get('s', get(vars)),[]],#process_info{method= <<"forceSignal"/utf8>>},Cog,[O,DC| Stack]),
                    future:get_blocking(TempFuture, Cog, [O,DC| Stack])
            end end)(),
            T_1;
            false ->          %% src/TrackElement.abs:154--154
        case cmp:eq(maps:get('id', get(vars)),1) of
            true ->  %% src/TrackElement.abs:155--155
            T_1 = (fun() -> case get(O,'s2') of
                null -> throw(dataNullPointerException);
                #object{ref=ObjRef,class=T,cog=Cog} ->
                    case is_process_alive(ObjRef) of
                        true ->
                            Vars=get(vars),
                            Result=T:'m_forceSignal'(get(O,'s2'),maps:get('s', get(vars)),[O,DC| Stack]),
                            put(vars, Vars),
                            Result;
                        false -> throw(dataObjectDeadException)
                    end;
                _ ->
                    TempFuture = future:start(get(O,'s2'),'m_forceSignal',[maps:get('s', get(vars)),[]],#process_info{method= <<"forceSignal"/utf8>>},Cog,[O,DC| Stack]),
                    future:get_blocking(TempFuture, Cog, [O,DC| Stack])
            end end)(),
            T_1;
            false ->         ok
        end
        end
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method forceSignal and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:159
 %% src/TrackElement.abs:159
'm_occupy'(O=#object{class=class_TrackElement_TrackElementFreeWay=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_tr_0,V_p_0,Stack)->
    put(vars, #{ 'this' => O,
 'tr' => V_tr_0,
 'p' => V_p_0 }),
    try
         %% src/TrackElement.abs:160--160
        T_1 = builtin:println(Cog,<<"-----------------------------------"/utf8>>),
        T_1,
         %% src/TrackElement.abs:161--161
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
         %% src/TrackElement.abs:162--162
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
         %% src/TrackElement.abs:163--163
        T_2 = builtin:println(Cog,iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([<<"-> ["/utf8>>, get(O,'name')]), <<"].occupy("/utf8>>]), builtin:toString(Cog,maps:get('iid', get(vars)))]), <<" ,"/utf8>>]), maps:get('na', get(vars))]), <<")"/utf8>>])),
        T_2,
         %% src/TrackElement.abs:165--165
        put(vars, (get(vars))#{'mt' => m_ABS_StdLib_funs:f_lookup(Cog,get(O,'pre2'),0,[O,DC| Stack])}),
         %% src/TrackElement.abs:166--166
        put(vars, (get(vars))#{'t' => m_ABS_StdLib_funs:f_fromJust(Cog,maps:get('mt', get(vars)),[O,DC| Stack])}),
         %% src/TrackElement.abs:167--167
        put(vars, (get(vars))#{'mt' := m_ABS_StdLib_funs:f_lookup(Cog,get(O,'pre2'),1,[O,DC| Stack])}),
         %% src/TrackElement.abs:168--168
        put(vars, (get(vars))#{'t2' => m_ABS_StdLib_funs:f_fromJust(Cog,maps:get('mt', get(vars)),[O,DC| Stack])}),
         %% src/TrackElement.abs:170--170
        case cmp:eq(get(O,'train'),null) of
            true ->  %% src/TrackElement.abs:171--171
            put(vars, (get(vars))#{'n' => null}),
             %% src/TrackElement.abs:172--172
            put(vars, (get(vars))#{'dir' => 0}),
             %% src/TrackElement.abs:173--173
            case cmp:eq(maps:get('p', get(vars)),maps:get('t', get(vars))) of
                true ->  %% src/TrackElement.abs:174--174
                put(vars, (get(vars))#{'n' := maps:get('t2', get(vars))}),
                 %% src/TrackElement.abs:175--175
                put(vars, (get(vars))#{'dir' := 0});
                false ->              %% src/TrackElement.abs:176--176
            case cmp:eq(maps:get('p', get(vars)),maps:get('t2', get(vars))) of
                true ->  %% src/TrackElement.abs:177--177
                put(vars, (get(vars))#{'n' := maps:get('t', get(vars))}),
                 %% src/TrackElement.abs:178--178
                put(vars, (get(vars))#{'dir' := 1});
                false ->             ok
            end
            end,
             %% src/TrackElement.abs:181--181
            put(vars, (get(vars))#{'tt' => (fun() -> case maps:get('n', get(vars)) of
                null -> throw(dataNullPointerException);
                #object{ref=ObjRef,class=T,cog=Cog} ->
                    case is_process_alive(ObjRef) of
                        true ->
                            Vars=get(vars),
                            Result=T:'m_getType'(maps:get('n', get(vars)),[O,DC| Stack]),
                            put(vars, Vars),
                            Result;
                        false -> throw(dataObjectDeadException)
                    end;
                _ ->
                    TempFuture = future:start(maps:get('n', get(vars)),'m_getType',[[]],#process_info{method= <<"getType"/utf8>>},Cog,[O,DC| Stack]),
                    future:get_blocking(TempFuture, Cog, [O,DC| Stack])
            end end)()}),
             %% src/TrackElement.abs:182--182
            case cmp:eq(maps:get('tt', get(vars)),dataFreeWay) of
                true ->  %% src/TrackElement.abs:183--183
                T_3 = (fun() -> case maps:get('tr', get(vars)) of
                    null -> throw(dataNullPointerException);
                    #object{ref=ObjRef,class=T,cog=Cog} ->
                        case is_process_alive(ObjRef) of
                            true ->
                                Vars=get(vars),
                                Result=T:'m_setNext'(maps:get('tr', get(vars)),maps:get('n', get(vars)),[O,DC| Stack]),
                                put(vars, Vars),
                                Result;
                            false -> throw(dataObjectDeadException)
                        end;
                    _ ->
                        TempFuture = future:start(maps:get('tr', get(vars)),'m_setNext',[maps:get('n', get(vars)),[]],#process_info{method= <<"setNext"/utf8>>},Cog,[O,DC| Stack]),
                        future:get_blocking(TempFuture, Cog, [O,DC| Stack])
                end end)(),
                T_3,
                 %% src/TrackElement.abs:184--184
                put(vars, (get(vars))#{'dir' := (fun() -> case maps:get('n', get(vars)) of
                    null -> throw(dataNullPointerException);
                    #object{ref=ObjRef,class=T,cog=Cog} ->
                        case is_process_alive(ObjRef) of
                            true ->
                                Vars=get(vars),
                                Result=T:'m_registerTrain'(maps:get('n', get(vars)),maps:get('tr', get(vars)),O,[O,DC| Stack]),
                                put(vars, Vars),
                                Result;
                            false -> throw(dataObjectDeadException)
                        end;
                    _ ->
                        TempFuture = future:start(maps:get('n', get(vars)),'m_registerTrain',[maps:get('tr', get(vars)),O,[]],#process_info{method= <<"registerTrain"/utf8>>},Cog,[O,DC| Stack]),
                        future:get_blocking(TempFuture, Cog, [O,DC| Stack])
                end end)()}),
                 %% src/TrackElement.abs:185--185
                case cmp:eq(maps:get('dir', get(vars)),0) of
                    true ->  %% src/TrackElement.abs:186--186
                    T_4 = (fun() -> case get(O,'s1') of
                        null -> throw(dataNullPointerException);
                        #object{ref=ObjRef,class=T,cog=Cog} ->
                            case is_process_alive(ObjRef) of
                                true ->
                                    Vars=get(vars),
                                    Result=T:'m_rueckblock'(get(O,'s1'),[O,DC| Stack]),
                                    put(vars, Vars),
                                    Result;
                                false -> throw(dataObjectDeadException)
                            end;
                        _ ->
                            TempFuture = future:start(get(O,'s1'),'m_rueckblock',[[]],#process_info{method= <<"rueckblock"/utf8>>},Cog,[O,DC| Stack]),
                            future:get_blocking(TempFuture, Cog, [O,DC| Stack])
                    end end)(),
                    T_4;
                    false ->                  %% src/TrackElement.abs:188--188
                T_4 = (fun() -> case get(O,'s2') of
                    null -> throw(dataNullPointerException);
                    #object{ref=ObjRef,class=T,cog=Cog} ->
                        case is_process_alive(ObjRef) of
                            true ->
                                Vars=get(vars),
                                Result=T:'m_rueckblock'(get(O,'s2'),[O,DC| Stack]),
                                put(vars, Vars),
                                Result;
                            false -> throw(dataObjectDeadException)
                        end;
                    _ ->
                        TempFuture = future:start(get(O,'s2'),'m_rueckblock',[[]],#process_info{method= <<"rueckblock"/utf8>>},Cog,[O,DC| Stack]),
                        future:get_blocking(TempFuture, Cog, [O,DC| Stack])
                end end)(),
                T_4
                end,
                 %% src/TrackElement.abs:190--190
                put(vars, (get(vars))#{'s' => (fun() -> case maps:get('n', get(vars)) of
                    null -> throw(dataNullPointerException);
                    #object{ref=ObjRef,class=T,cog=Cog} ->
                        case is_process_alive(ObjRef) of
                            true ->
                                Vars=get(vars),
                                Result=T:'m_getSignal'(maps:get('n', get(vars)),maps:get('dir', get(vars)),[O,DC| Stack]),
                                put(vars, Vars),
                                Result;
                            false -> throw(dataObjectDeadException)
                        end;
                    _ ->
                        TempFuture = future:start(maps:get('n', get(vars)),'m_getSignal',[maps:get('dir', get(vars)),[]],#process_info{method= <<"getSignal"/utf8>>},Cog,[O,DC| Stack]),
                        future:get_blocking(TempFuture, Cog, [O,DC| Stack])
                end end)()}),
                 %% src/TrackElement.abs:191--191
                T_5 = (fun() -> case maps:get('s', get(vars)) of
                    null -> throw(dataNullPointerException);
                    #object{ref=ObjRef,class=T,cog=Cog} ->
                        case is_process_alive(ObjRef) of
                            true ->
                                Vars=get(vars),
                                Result=T:'m_vorblock'(maps:get('s', get(vars)),[O,DC| Stack]),
                                put(vars, Vars),
                                Result;
                            false -> throw(dataObjectDeadException)
                        end;
                    _ ->
                        TempFuture = future:start(maps:get('s', get(vars)),'m_vorblock',[[]],#process_info{method= <<"vorblock"/utf8>>},Cog,[O,DC| Stack]),
                        future:get_blocking(TempFuture, Cog, [O,DC| Stack])
                end end)(),
                T_5;
                false ->              %% src/TrackElement.abs:192--192
            case cmp:eq(maps:get('tt', get(vars)),dataPre) of
                true ->  %% src/TrackElement.abs:193--193
                T_3 = (fun() -> case maps:get('tr', get(vars)) of
                    null -> throw(dataNullPointerException);
                    #object{ref=ObjRef,class=T,cog=Cog} ->
                        case is_process_alive(ObjRef) of
                            true ->
                                Vars=get(vars),
                                Result=T:'m_setDriveIn'(maps:get('tr', get(vars)),maps:get('n', get(vars)),[O,DC| Stack]),
                                put(vars, Vars),
                                Result;
                            false -> throw(dataObjectDeadException)
                        end;
                    _ ->
                        TempFuture = future:start(maps:get('tr', get(vars)),'m_setDriveIn',[maps:get('n', get(vars)),[]],#process_info{method= <<"setDriveIn"/utf8>>},Cog,[O,DC| Stack]),
                        future:get_blocking(TempFuture, Cog, [O,DC| Stack])
                end end)(),
                T_3,
                 %% src/TrackElement.abs:194--194
                T_4 = (fun() -> case maps:get('n', get(vars)) of
                    null -> throw(dataNullPointerException);
                    #object{ref=ObjRef,class=T,cog=Cog} ->
                        case is_process_alive(ObjRef) of
                            true ->
                                Vars=get(vars),
                                Result=T:'m_drive_in'(maps:get('n', get(vars)),maps:get('tr', get(vars)),[O,DC| Stack]),
                                put(vars, Vars),
                                Result;
                            false -> throw(dataObjectDeadException)
                        end;
                    _ ->
                        TempFuture = future:start(maps:get('n', get(vars)),'m_drive_in',[maps:get('tr', get(vars)),[]],#process_info{method= <<"drive_in"/utf8>>},Cog,[O,DC| Stack]),
                        future:get_blocking(TempFuture, Cog, [O,DC| Stack])
                end end)(),
                T_4,
                 %% src/TrackElement.abs:195--195
                T_5 = (fun() -> case O of
                    null -> throw(dataNullPointerException);
                    #object{ref=ObjRef,class=T,cog=Cog} ->
                        case is_process_alive(ObjRef) of
                            true ->
                                Vars=get(vars),
                                Result=T:'m_forceSignal'(O,maps:get('dir', get(vars)),dataRED,[O,DC| Stack]),
                                put(vars, Vars),
                                Result;
                            false -> throw(dataObjectDeadException)
                        end;
                    _ ->
                        TempFuture = future:start(O,'m_forceSignal',[maps:get('dir', get(vars)),dataRED,[]],#process_info{method= <<"forceSignal"/utf8>>},Cog,[O,DC| Stack]),
                        future:get_blocking(TempFuture, Cog, [O,DC| Stack])
                end end)(),
                T_5;
                false ->             ok
            end
            end;
            false ->          %% src/TrackElement.abs:198--198
        T_3 = builtin:println(Cog,<<"track already occupied"/utf8>>),
        T_3
        end,
         %% src/TrackElement.abs:200--200
        T_6 = builtin:println(Cog,<<"--------------------------------------"/utf8>>),
        T_6,
         %% src/TrackElement.abs:201--201
        false
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method occupy and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:204
 %% src/TrackElement.abs:204
'm_drive_in'(O=#object{class=class_TrackElement_TrackElementFreeWay=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_tr_0,Stack)->
    put(vars, #{ 'this' => O,
 'tr' => V_tr_0 }),
    try
        ok
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method drive_in and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
'set'(O=#object{class=class_TrackElement_TrackElementFreeWay=C,ref=Ref,cog=Cog},Var,Val)->
    object:set_field_value(O, Var, Val).

'get'(O=#object{class=class_TrackElement_TrackElementFreeWay=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Var)->
    object:get_field_value(O,Var).

-record(state,{'name'=null,'train'=null,'s1'=null,'s2'=null,'pre'=null,'pre2'=null,'gegenfahrschutz'=null,'occupied'=null}).
'init_internal'()->
    #state{}.

 %% src/TrackElement.abs:29
'get_val_internal'(#state{'name'=G},'name')->
    G;
 %% src/TrackElement.abs:31
'get_val_internal'(#state{'train'=G},'train')->
    G;
 %% src/TrackElement.abs:32
'get_val_internal'(#state{'s1'=G},'s1')->
    G;
 %% src/TrackElement.abs:33
'get_val_internal'(#state{'s2'=G},'s2')->
    G;
 %% src/TrackElement.abs:34
'get_val_internal'(#state{'pre'=G},'pre')->
    G;
 %% src/TrackElement.abs:35
'get_val_internal'(#state{'pre2'=G},'pre2')->
    G;
 %% src/TrackElement.abs:36
'get_val_internal'(#state{'gegenfahrschutz'=G},'gegenfahrschutz')->
    G;
 %% src/TrackElement.abs:37
'get_val_internal'(#state{'occupied'=G},'occupied')->
    G;
'get_val_internal'(_,_)->
    %% Invalid return value; handled by HTTP API when querying for non-existant field.
    %% Will never occur in generated code.
    none.

 %% src/TrackElement.abs:29
'set_val_internal'(S,'name',V)->
    S#state{'name'=V};
 %% src/TrackElement.abs:31
'set_val_internal'(S,'train',V)->
    S#state{'train'=V};
 %% src/TrackElement.abs:32
'set_val_internal'(S,'s1',V)->
    S#state{'s1'=V};
 %% src/TrackElement.abs:33
'set_val_internal'(S,'s2',V)->
    S#state{'s2'=V};
 %% src/TrackElement.abs:34
'set_val_internal'(S,'pre',V)->
    S#state{'pre'=V};
 %% src/TrackElement.abs:35
'set_val_internal'(S,'pre2',V)->
    S#state{'pre2'=V};
 %% src/TrackElement.abs:36
'set_val_internal'(S,'gegenfahrschutz',V)->
    S#state{'gegenfahrschutz'=V};
 %% src/TrackElement.abs:37
'set_val_internal'(S,'occupied',V)->
    S#state{'occupied'=V}.

'get_state_for_modelapi'(S)->
    [
        { 'name', S#state.'name' }
        , { 'train', S#state.'train' }
        , { 's1', S#state.'s1' }
        , { 's2', S#state.'s2' }
        , { 'pre', S#state.'pre' }
        , { 'pre2', S#state.'pre2' }
        , { 'gegenfahrschutz', S#state.'gegenfahrschutz' }
        , { 'occupied', S#state.'occupied' }
    ].
