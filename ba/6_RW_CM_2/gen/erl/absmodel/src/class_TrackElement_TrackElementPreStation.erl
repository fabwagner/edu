-module(class_TrackElement_TrackElementPreStation).
-include_lib("../include/abs_types.hrl").
-behaviour(object).
-export([get_val_internal/2,set_val_internal/3,init_internal/0,get_state_for_modelapi/1]).
-compile(export_all).

exported() -> #{  }.

'init'(O=#object{class=class_TrackElement_TrackElementPreStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},[P_name,Stack])->
    put(vars, #{}),
    set(O,'name',P_name),
     %% src/TrackElement.abs:266--266
    set(O,'train',null),
     %% src/TrackElement.abs:268--268
    set(O,'s1',null),
     %% src/TrackElement.abs:269--269
    set(O,'s2',null),
     %% src/TrackElement.abs:270--270
    set(O,'pre',[]),
     %% src/TrackElement.abs:271--271
    set(O,'gegenfahrschutz',false),
     %% src/TrackElement.abs:272--272
    set(O,'st',null),
    O.
 %% src/TrackElement.abs:274
 %% src/TrackElement.abs:274
'm_printName'(O=#object{class=class_TrackElement_TrackElementPreStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
         %% src/TrackElement.abs:275--275
        T_1 = builtin:println(Cog,<<"TrackElement PreStation"/utf8>>),
        T_1,
         %% src/TrackElement.abs:276--276
        T_2 = builtin:println(Cog,get(O,'name')),
        T_2
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method printName and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:279
 %% src/TrackElement.abs:279
'm_getSignal'(O=#object{class=class_TrackElement_TrackElementPreStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_id_0,Stack)->
    put(vars, #{ 'this' => O,
 'id' => V_id_0 }),
    try
         %% src/TrackElement.abs:280--280
        put(vars, (get(vars))#{'retVal' => null}),
         %% src/TrackElement.abs:281--281
        case cmp:eq(maps:get('id', get(vars)),0) of
            true ->  %% src/TrackElement.abs:282--282
            put(vars, (get(vars))#{'retVal' := get(O,'s1')});
            false ->          %% src/TrackElement.abs:284--284
        put(vars, (get(vars))#{'retVal' := get(O,'s2')})
        end,
         %% src/TrackElement.abs:285--285
        maps:get('retVal', get(vars))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method getSignal and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:288
 %% src/TrackElement.abs:288
'm_getTrackElement'(O=#object{class=class_TrackElement_TrackElementPreStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_id_0,Stack)->
    put(vars, #{ 'this' => O,
 'id' => V_id_0 }),
    try
         %% src/TrackElement.abs:289--289
        put(vars, (get(vars))#{'retVal' => m_ABS_StdLib_funs:f_nth(Cog,get(O,'pre'),maps:get('id', get(vars)),[O,DC| Stack])}),
         %% src/TrackElement.abs:290--290
        maps:get('retVal', get(vars))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method getTrackElement and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:292
 %% src/TrackElement.abs:292
'm_registerDriveOut'(O=#object{class=class_TrackElement_TrackElementPreStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_tr_0,Stack)->
    put(vars, #{ 'this' => O,
 'tr' => V_tr_0 }),
    try
         %% src/TrackElement.abs:293--293
        T_1 = (fun() -> case get(O,'s1') of
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
        T_1
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method registerDriveOut and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:296
 %% src/TrackElement.abs:296
'm_forceSet'(O=#object{class=class_TrackElement_TrackElementPreStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_t_0,V_id_0,Stack)->
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
 %% src/TrackElement.abs:298
 %% src/TrackElement.abs:298
'm_registerTrain'(O=#object{class=class_TrackElement_TrackElementPreStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_tr_0,V_p_0,Stack)->
    put(vars, #{ 'this' => O,
 'tr' => V_tr_0,
 'p' => V_p_0 }),
    try
         %% src/TrackElement.abs:299--299
        T_1 = builtin:println(Cog,iolist_to_binary([iolist_to_binary([<<"-> ["/utf8>>, get(O,'name')]), <<"].registerTrain(...)"/utf8>>])),
        T_1,
         %% src/TrackElement.abs:301--301
        T_2 = (fun() -> case get(O,'s2') of
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
        T_2,
         %% src/TrackElement.abs:302--302
        1
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method registerTrain and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:305
 %% src/TrackElement.abs:305
'm_forceSignal'(O=#object{class=class_TrackElement_TrackElementPreStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_id_0,V_s_0,Stack)->
    put(vars, #{ 'this' => O,
 'id' => V_id_0,
 's' => V_s_0 }),
    try
         %% src/TrackElement.abs:306--306
        case cmp:eq(maps:get('id', get(vars)),0) of
            true ->  %% src/TrackElement.abs:307--307
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
            false ->          %% src/TrackElement.abs:308--308
        case cmp:eq(maps:get('id', get(vars)),1) of
            true ->  %% src/TrackElement.abs:309--309
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
 %% src/TrackElement.abs:312
 %% src/TrackElement.abs:312
'm_getType'(O=#object{class=class_TrackElement_TrackElementPreStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
         %% src/TrackElement.abs:313--313
        dataPre
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method getType and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:316
 %% src/TrackElement.abs:316
'm_getName'(O=#object{class=class_TrackElement_TrackElementPreStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
         %% src/TrackElement.abs:317--317
        get(O,'name')
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method getName and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:321
 %% src/TrackElement.abs:321
'm_construct'(O=#object{class=class_TrackElement_TrackElementPreStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_pre_0,V_stations_0,Stack)->
    put(vars, #{ 'this' => O,
 'pre' => V_pre_0,
 'stations' => V_stations_0 }),
    try
         %% src/TrackElement.abs:322--322
        T_1 = builtin:println(Cog,iolist_to_binary([iolist_to_binary([<<"-> ["/utf8>>, get(O,'name')]), <<"].construct(...)"/utf8>>])),
        T_1,
         %% src/TrackElement.abs:323--323
        set(O,'s1',object:new(cog:start(DC),class_Signal_SignalAusfahrt,[[]],Cog,[O,DC| Stack])),
         %% src/TrackElement.abs:324--324
        set(O,'s2',object:new(cog:start(DC),class_Signal_SignalEinfahrt,[[]],Cog,[O,DC| Stack])),
         %% src/TrackElement.abs:326--326
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
         %% src/TrackElement.abs:327--327
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
         %% src/TrackElement.abs:328--328
        set(O,'pre',maps:get('pre', get(vars))),
         %% src/TrackElement.abs:329--329
        set(O,'st',m_ABS_StdLib_funs:f_nth(Cog,maps:get('stations', get(vars)),0,[O,DC| Stack])),
         %% src/TrackElement.abs:330--330
        true
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method construct and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:334
 %% src/TrackElement.abs:334
'm_occupy'(O=#object{class=class_TrackElement_TrackElementPreStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_tr_0,V_p_0,Stack)->
    put(vars, #{ 'this' => O,
 'tr' => V_tr_0,
 'p' => V_p_0 }),
    try
         %% src/TrackElement.abs:335--335
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
         %% src/TrackElement.abs:337--337
        put(vars, (get(vars))#{'na' => <<"null"/utf8>>}),
         %% src/TrackElement.abs:338--338
        case (not cmp:eq(maps:get('p', get(vars)),null)) of
            true ->  %% src/TrackElement.abs:339--339
            put(vars, (get(vars))#{'na' := (fun() -> case maps:get('p', get(vars)) of
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
            end end)()});
            false ->         ok
        end,
         %% src/TrackElement.abs:340--340
        T_1 = builtin:println(Cog,iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([<<"-> ["/utf8>>, get(O,'name')]), <<"].occupy("/utf8>>]), builtin:toString(Cog,maps:get('iid', get(vars)))]), <<", "/utf8>>]), maps:get('na', get(vars))]), <<")"/utf8>>])),
        T_1,
         %% src/TrackElement.abs:342--342
        case cmp:eq(maps:get('p', get(vars)),null) of
            true ->  %% src/TrackElement.abs:343--343
            put(vars, (get(vars))#{'t' => m_ABS_StdLib_funs:f_nth(Cog,get(O,'pre'),0,[O,DC| Stack])}),
             %% src/TrackElement.abs:344--344
            put(vars, (get(vars))#{'tmp1908455234' => future:start(maps:get('t', get(vars)),'m_getType',[[]],#process_info{method= <<"getType"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack])}),
             %% src/TrackElement.abs:344--344
            future:await(maps:get('tmp1908455234', get(vars)), Cog, [O,DC| Stack]),
            ok,
             %% src/TrackElement.abs:344--344
            put(vars, (get(vars))#{'ttype' => future:get_blocking(maps:get('tmp1908455234', get(vars)), Cog, [O,DC| Stack])}),
             %% src/TrackElement.abs:345--345
            put(vars, (get(vars))#{'dir' => 0}),
             %% src/TrackElement.abs:346--346
            case cmp:eq(maps:get('ttype', get(vars)),dataStation) of
                true ->  %% src/TrackElement.abs:347--347
                T_2 = builtin:println(Cog,<<"station..."/utf8>>),
                T_2,
                 %% src/TrackElement.abs:348--348
                put(vars, (get(vars))#{'t' := m_ABS_StdLib_funs:f_nth(Cog,get(O,'pre'),1,[O,DC| Stack])}),
                 %% src/TrackElement.abs:349--349
                put(vars, (get(vars))#{'dir' := 1});
                false ->             ok
            end,
             %% src/TrackElement.abs:352--352
            T_3 = (fun() -> case maps:get('tr', get(vars)) of
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
            T_3,
             %% src/TrackElement.abs:353--353
            T_4 = future:start(maps:get('t', get(vars)),'m_registerTrain',[maps:get('tr', get(vars)),O,[]],#process_info{method= <<"registerTrain"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack]),
            T_4,
             %% src/TrackElement.abs:354--354
            T_5 = future:start(O,'m_forceSignal',[0,dataRED,[]],#process_info{method= <<"forceSignal"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack]),
            T_5,
             %% src/TrackElement.abs:355--355
            T_6 = future:start(maps:get('t', get(vars)),'m_forceSignal',[0,dataGREEN,[]],#process_info{method= <<"forceSignal"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack]),
            T_6;
            false ->         ok
        end,
         %% src/TrackElement.abs:357--357
        true
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method occupy and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% src/TrackElement.abs:360
 %% src/TrackElement.abs:360
'm_drive_in'(O=#object{class=class_TrackElement_TrackElementPreStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_tr_0,Stack)->
    put(vars, #{ 'this' => O,
 'tr' => V_tr_0 }),
    try
         %% src/TrackElement.abs:361--361
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
         %% src/TrackElement.abs:362--362
        T_1 = builtin:println(Cog,iolist_to_binary([iolist_to_binary([iolist_to_binary([iolist_to_binary([<<"-> ["/utf8>>, get(O,'name')]), <<"].drive_in("/utf8>>]), builtin:toString(Cog,maps:get('iid', get(vars)))]), <<")"/utf8>>])),
        T_1,
         %% src/TrackElement.abs:363--363
        T_2 = (fun() -> case get(O,'s2') of
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
        T_2,
         %% src/TrackElement.abs:364--364
        put(vars, (get(vars))#{'tmp588389652' => future:start(get(O,'st'),'m_askDriveIn',[maps:get('tr', get(vars)),[]],#process_info{method= <<"askDriveIn"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack])}),
         %% src/TrackElement.abs:364--364
        future:await(maps:get('tmp588389652', get(vars)), Cog, [O,DC| Stack]),
        ok,
         %% src/TrackElement.abs:364--364
        put(vars, (get(vars))#{'answer' => future:get_blocking(maps:get('tmp588389652', get(vars)), Cog, [O,DC| Stack])}),
         %% src/TrackElement.abs:365--365
        case maps:get('answer', get(vars)) of
            true ->  %% src/TrackElement.abs:366--366
            T_3 = (fun() -> case maps:get('tr', get(vars)) of
                null -> throw(dataNullPointerException);
                #object{ref=ObjRef,class=T,cog=Cog} ->
                    case is_process_alive(ObjRef) of
                        true ->
                            Vars=get(vars),
                            Result=T:'m_setDriveInStation'(maps:get('tr', get(vars)),get(O,'st'),[O,DC| Stack]),
                            put(vars, Vars),
                            Result;
                        false -> throw(dataObjectDeadException)
                    end;
                _ ->
                    TempFuture = future:start(maps:get('tr', get(vars)),'m_setDriveInStation',[get(O,'st'),[]],#process_info{method= <<"setDriveInStation"/utf8>>},Cog,[O,DC| Stack]),
                    future:get_blocking(TempFuture, Cog, [O,DC| Stack])
            end end)(),
            T_3,
             %% src/TrackElement.abs:367--367
            T_4 = (fun() -> case get(O,'s2') of
                null -> throw(dataNullPointerException);
                #object{ref=ObjRef,class=T,cog=Cog} ->
                    case is_process_alive(ObjRef) of
                        true ->
                            Vars=get(vars),
                            Result=T:'m_forceSignal'(get(O,'s2'),dataGREEN,[O,DC| Stack]),
                            put(vars, Vars),
                            Result;
                        false -> throw(dataObjectDeadException)
                    end;
                _ ->
                    TempFuture = future:start(get(O,'s2'),'m_forceSignal',[dataGREEN,[]],#process_info{method= <<"forceSignal"/utf8>>},Cog,[O,DC| Stack]),
                    future:get_blocking(TempFuture, Cog, [O,DC| Stack])
            end end)(),
            T_4;
            false ->         ok
        end
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method drive_in and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
'set'(O=#object{class=class_TrackElement_TrackElementPreStation=C,ref=Ref,cog=Cog},Var,Val)->
    object:set_field_value(O, Var, Val).

'get'(O=#object{class=class_TrackElement_TrackElementPreStation=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Var)->
    object:get_field_value(O,Var).

-record(state,{'name'=null,'train'=null,'s1'=null,'s2'=null,'pre'=null,'gegenfahrschutz'=null,'st'=null}).
'init_internal'()->
    #state{}.

 %% src/TrackElement.abs:265
'get_val_internal'(#state{'name'=G},'name')->
    G;
 %% src/TrackElement.abs:266
'get_val_internal'(#state{'train'=G},'train')->
    G;
 %% src/TrackElement.abs:268
'get_val_internal'(#state{'s1'=G},'s1')->
    G;
 %% src/TrackElement.abs:269
'get_val_internal'(#state{'s2'=G},'s2')->
    G;
 %% src/TrackElement.abs:270
'get_val_internal'(#state{'pre'=G},'pre')->
    G;
 %% src/TrackElement.abs:271
'get_val_internal'(#state{'gegenfahrschutz'=G},'gegenfahrschutz')->
    G;
 %% src/TrackElement.abs:272
'get_val_internal'(#state{'st'=G},'st')->
    G;
'get_val_internal'(_,_)->
    %% Invalid return value; handled by HTTP API when querying for non-existant field.
    %% Will never occur in generated code.
    none.

 %% src/TrackElement.abs:265
'set_val_internal'(S,'name',V)->
    S#state{'name'=V};
 %% src/TrackElement.abs:266
'set_val_internal'(S,'train',V)->
    S#state{'train'=V};
 %% src/TrackElement.abs:268
'set_val_internal'(S,'s1',V)->
    S#state{'s1'=V};
 %% src/TrackElement.abs:269
'set_val_internal'(S,'s2',V)->
    S#state{'s2'=V};
 %% src/TrackElement.abs:270
'set_val_internal'(S,'pre',V)->
    S#state{'pre'=V};
 %% src/TrackElement.abs:271
'set_val_internal'(S,'gegenfahrschutz',V)->
    S#state{'gegenfahrschutz'=V};
 %% src/TrackElement.abs:272
'set_val_internal'(S,'st',V)->
    S#state{'st'=V}.

'get_state_for_modelapi'(S)->
    [
        { 'name', S#state.'name' }
        , { 'train', S#state.'train' }
        , { 's1', S#state.'s1' }
        , { 's2', S#state.'s2' }
        , { 'pre', S#state.'pre' }
        , { 'gegenfahrschutz', S#state.'gegenfahrschutz' }
        , { 'st', S#state.'st' }
    ].
