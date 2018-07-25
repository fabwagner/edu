-module(class_ABS_DC_CloudProvider).
-include_lib("../include/abs_types.hrl").
-behaviour(object).
-export([get_val_internal/2,set_val_internal/3,init_internal/0,get_state_for_modelapi/1]).
-compile(export_all).

exported() -> #{  }.

'init'(O=#object{class=class_ABS_DC_CloudProvider=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},[P_name,Stack])->
    put(vars, #{}),
    set(O,'name',P_name),
     %% abs/lang/abslang.abs:845--845
    set(O,'instanceDescriptions',m_ABS_StdLib_funs:f_map(Cog,[],[O,DC| Stack])),
     %% abs/lang/abslang.abs:848--848
    set(O,'launchedInstances',m_ABS_StdLib_funs:f_set(Cog,[],[O,DC| Stack])),
     %% abs/lang/abslang.abs:850--850
    set(O,'acquiredInstances',m_ABS_StdLib_funs:f_set(Cog,[],[O,DC| Stack])),
     %% abs/lang/abslang.abs:851--851
    set(O,'killedInstances',m_ABS_StdLib_funs:f_set(Cog,[],[O,DC| Stack])),
     %% abs/lang/abslang.abs:852--852
    set(O,'nextInstanceId',0),
     %% abs/lang/abslang.abs:853--853
    set(O,'accumulatedCostOfKilledDCs',0),
    O.
 %% abs/lang/abslang.abs:855
 %% abs/lang/abslang.abs:855
'm_shutdown'(O=#object{class=class_ABS_DC_CloudProvider=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
         %% abs/lang/abslang.abs:857--857
        skip
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method shutdown and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% abs/lang/abslang.abs:860
 %% abs/lang/abslang.abs:860
'm_createInstance'(O=#object{class=class_ABS_DC_CloudProvider=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_instancename_0,V_d_0,Stack)->
    put(vars, #{ 'this' => O,
 'instancename' => V_instancename_0,
 'd' => V_d_0 }),
    try
         %% abs/lang/abslang.abs:861--861
        put(vars, (get(vars))#{'mightNeedToStartAccounting' => m_ABS_StdLib_funs:f_emptySet(Cog,get(O,'launchedInstances'),[O,DC| Stack])}),
         %% abs/lang/abslang.abs:862--863
        put(vars, (get(vars))#{'result' => object:new(cog:start(),class_ABS_DC_DeploymentComponent,[iolist_to_binary([iolist_to_binary([maps:get('instancename', get(vars)), <<"-"/utf8>>]), builtin:toString(Cog,get(O,'nextInstanceId'))]),maps:get('d', get(vars)),[]],Cog,[O,DC| Stack])}),
        cog_monitor:new_dc(maps:get('result', get(vars))),
         %% abs/lang/abslang.abs:864--864
        T_1 = future:start(maps:get('result', get(vars)),'m_setProvider',[O,[]],#process_info{method= <<"setProvider"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack]),
        T_1,
         %% abs/lang/abslang.abs:865--865
        set(O,'nextInstanceId',(get(O,'nextInstanceId') + 1) ),
         %% abs/lang/abslang.abs:868--868
        put(vars, (get(vars))#{'stupidTypeSystem' => maps:get('result', get(vars))}),
         %% abs/lang/abslang.abs:869--869
        set(O,'launchedInstances',m_ABS_StdLib_funs:f_insertElement(Cog,get(O,'launchedInstances'),maps:get('stupidTypeSystem', get(vars)),[O,DC| Stack])),
         %% abs/lang/abslang.abs:870--870
        maps:get('result', get(vars))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method createInstance and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% abs/lang/abslang.abs:873
 %% abs/lang/abslang.abs:873
'm_prelaunchInstance'(O=#object{class=class_ABS_DC_CloudProvider=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_d_0,Stack)->
    put(vars, #{ 'this' => O,
 'd' => V_d_0 }),
    try
         %% abs/lang/abslang.abs:874--874
        put(vars, (get(vars))#{'result' => (fun() -> case O of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_createInstance'(O,get(O,'name'),maps:get('d', get(vars)),[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(O,'m_createInstance',[get(O,'name'),maps:get('d', get(vars)),[]],#process_info{method= <<"createInstance"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)()}),
         %% abs/lang/abslang.abs:875--875
        put(vars, (get(vars))#{'tmp2005492533' => future:start(maps:get('result', get(vars)),'m_getStartupDuration',[[]],#process_info{method= <<"getStartupDuration"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack])}),
         %% abs/lang/abslang.abs:875--875
        future:await(maps:get('tmp2005492533', get(vars)), Cog, [O,DC| Stack]),
        ok,
         %% abs/lang/abslang.abs:875--875
        put(vars, (get(vars))#{'startup_duration' => future:get_blocking(maps:get('tmp2005492533', get(vars)), Cog, [O,DC| Stack])}),
         %% abs/lang/abslang.abs:876--876
        task:await_duration(Cog,maps:get('startup_duration', get(vars)),maps:get('startup_duration', get(vars)),[O,DC| Stack]),
        ok,
         %% abs/lang/abslang.abs:877--877
        maps:get('result', get(vars))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method prelaunchInstance and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% abs/lang/abslang.abs:880
 %% abs/lang/abslang.abs:880
'm_prelaunchInstanceNamed'(O=#object{class=class_ABS_DC_CloudProvider=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_instancename_0,Stack)->
    put(vars, #{ 'this' => O,
 'instancename' => V_instancename_0 }),
    try
         %% abs/lang/abslang.abs:881--881
        put(vars, (get(vars))#{'mconfig' => m_ABS_StdLib_funs:f_lookup(Cog,get(O,'instanceDescriptions'),maps:get('instancename', get(vars)),[O,DC| Stack])}),
         %% abs/lang/abslang.abs:882--882
        put(vars, (get(vars))#{'dc' => null}),
         %% abs/lang/abslang.abs:883--883
        case m_ABS_StdLib_funs:f_isJust(Cog,maps:get('mconfig', get(vars)),[O,DC| Stack]) of
            true ->  %% abs/lang/abslang.abs:884--884
            put(vars, (get(vars))#{'config' => m_ABS_StdLib_funs:f_fromJust(Cog,maps:get('mconfig', get(vars)),[O,DC| Stack])}),
             %% abs/lang/abslang.abs:885--885
            put(vars, (get(vars))#{'dc' := (fun() -> case O of
                null -> throw(dataNullPointerException);
                #object{ref=ObjRef,class=T,cog=Cog} ->
                    case is_process_alive(ObjRef) of
                        true ->
                            Vars=get(vars),
                            Result=T:'m_createInstance'(O,iolist_to_binary([iolist_to_binary([get(O,'name'), <<"-"/utf8>>]), maps:get('instancename', get(vars))]),maps:get('config', get(vars)),[O,DC| Stack]),
                            put(vars, Vars),
                            Result;
                        false -> throw(dataObjectDeadException)
                    end;
                _ ->
                    TempFuture = future:start(O,'m_createInstance',[iolist_to_binary([iolist_to_binary([get(O,'name'), <<"-"/utf8>>]), maps:get('instancename', get(vars))]),maps:get('config', get(vars)),[]],#process_info{method= <<"createInstance"/utf8>>},Cog,[O,DC| Stack]),
                    future:get_blocking(TempFuture, Cog, [O,DC| Stack])
            end end)()});
            false ->         ok
        end,
         %% abs/lang/abslang.abs:887--887
        put(vars, (get(vars))#{'tmp905594127' => future:start(maps:get('dc', get(vars)),'m_getStartupDuration',[[]],#process_info{method= <<"getStartupDuration"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack])}),
         %% abs/lang/abslang.abs:887--887
        future:await(maps:get('tmp905594127', get(vars)), Cog, [O,DC| Stack]),
        ok,
         %% abs/lang/abslang.abs:887--887
        put(vars, (get(vars))#{'startup_duration' => future:get_blocking(maps:get('tmp905594127', get(vars)), Cog, [O,DC| Stack])}),
         %% abs/lang/abslang.abs:888--888
        task:await_duration(Cog,maps:get('startup_duration', get(vars)),maps:get('startup_duration', get(vars)),[O,DC| Stack]),
        ok,
         %% abs/lang/abslang.abs:889--889
        maps:get('dc', get(vars))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method prelaunchInstanceNamed and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% abs/lang/abslang.abs:892
 %% abs/lang/abslang.abs:892
'm_launchInstance'(O=#object{class=class_ABS_DC_CloudProvider=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_d_0,Stack)->
    put(vars, #{ 'this' => O,
 'd' => V_d_0 }),
    try
         %% abs/lang/abslang.abs:893--893
        put(vars, (get(vars))#{'result' => (fun() -> case O of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_prelaunchInstance'(O,maps:get('d', get(vars)),[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(O,'m_prelaunchInstance',[maps:get('d', get(vars)),[]],#process_info{method= <<"prelaunchInstance"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)()}),
         %% abs/lang/abslang.abs:894--894
        set(O,'acquiredInstances',m_ABS_StdLib_funs:f_insertElement(Cog,get(O,'acquiredInstances'),maps:get('result', get(vars)),[O,DC| Stack])),
         %% abs/lang/abslang.abs:895--895
        maps:get('result', get(vars))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method launchInstance and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% abs/lang/abslang.abs:898
 %% abs/lang/abslang.abs:898
'm_launchInstanceNamed'(O=#object{class=class_ABS_DC_CloudProvider=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_instancename_0,Stack)->
    put(vars, #{ 'this' => O,
 'instancename' => V_instancename_0 }),
    try
         %% abs/lang/abslang.abs:899--899
        put(vars, (get(vars))#{'result' => (fun() -> case O of
            null -> throw(dataNullPointerException);
            #object{ref=ObjRef,class=T,cog=Cog} ->
                case is_process_alive(ObjRef) of
                    true ->
                        Vars=get(vars),
                        Result=T:'m_prelaunchInstanceNamed'(O,maps:get('instancename', get(vars)),[O,DC| Stack]),
                        put(vars, Vars),
                        Result;
                    false -> throw(dataObjectDeadException)
                end;
            _ ->
                TempFuture = future:start(O,'m_prelaunchInstanceNamed',[maps:get('instancename', get(vars)),[]],#process_info{method= <<"prelaunchInstanceNamed"/utf8>>},Cog,[O,DC| Stack]),
                future:get_blocking(TempFuture, Cog, [O,DC| Stack])
        end end)()}),
         %% abs/lang/abslang.abs:900--900
        case (not cmp:eq(maps:get('result', get(vars)),null)) of
            true ->  %% abs/lang/abslang.abs:901--901
            set(O,'acquiredInstances',m_ABS_StdLib_funs:f_insertElement(Cog,get(O,'acquiredInstances'),maps:get('result', get(vars)),[O,DC| Stack]));
            false ->         ok
        end,
         %% abs/lang/abslang.abs:903--903
        maps:get('result', get(vars))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method launchInstanceNamed and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% abs/lang/abslang.abs:906
 %% abs/lang/abslang.abs:906
'm_acquireInstance'(O=#object{class=class_ABS_DC_CloudProvider=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_instance_0,Stack)->
    put(vars, #{ 'this' => O,
 'instance' => V_instance_0 }),
    try
         %% abs/lang/abslang.abs:907--907
        put(vars, (get(vars))#{'result' => true}),
         %% abs/lang/abslang.abs:908--908
        put(vars, (get(vars))#{'tmp1095446005' => future:start(maps:get('instance', get(vars)),'m_getProvider',[[]],#process_info{method= <<"getProvider"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack])}),
         %% abs/lang/abslang.abs:908--908
        future:await(maps:get('tmp1095446005', get(vars)), Cog, [O,DC| Stack]),
        ok,
         %% abs/lang/abslang.abs:908--908
        put(vars, (get(vars))#{'cp' => future:get_blocking(maps:get('tmp1095446005', get(vars)), Cog, [O,DC| Stack])}),
         %% abs/lang/abslang.abs:909--909
        case (not cmp:eq(maps:get('cp', get(vars)),O)) of
            true ->  %% abs/lang/abslang.abs:911--911
            put(vars, (get(vars))#{'result' := false});
            false ->          %% abs/lang/abslang.abs:912--913
        case (m_ABS_StdLib_funs:f_contains(Cog,get(O,'acquiredInstances'),maps:get('instance', get(vars)),[O,DC| Stack])) or (m_ABS_StdLib_funs:f_contains(Cog,get(O,'killedInstances'),maps:get('instance', get(vars)),[O,DC| Stack])) of
            true ->  %% abs/lang/abslang.abs:914--914
            put(vars, (get(vars))#{'result' := false});
            false ->          %% abs/lang/abslang.abs:916--916
        set(O,'acquiredInstances',m_ABS_StdLib_funs:f_insertElement(Cog,get(O,'acquiredInstances'),maps:get('instance', get(vars)),[O,DC| Stack]))
        end
        end,
         %% abs/lang/abslang.abs:918--918
        maps:get('result', get(vars))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method acquireInstance and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% abs/lang/abslang.abs:920
 %% abs/lang/abslang.abs:920
'm_releaseInstance'(O=#object{class=class_ABS_DC_CloudProvider=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_instance_0,Stack)->
    put(vars, #{ 'this' => O,
 'instance' => V_instance_0 }),
    try
         %% abs/lang/abslang.abs:925--925
        case m_ABS_StdLib_funs:f_contains(Cog,get(O,'acquiredInstances'),maps:get('instance', get(vars)),[O,DC| Stack]) of
            true ->  %% abs/lang/abslang.abs:926--926
            set(O,'acquiredInstances',m_ABS_StdLib_funs:f_remove(Cog,get(O,'acquiredInstances'),maps:get('instance', get(vars)),[O,DC| Stack]));
            false ->         ok
        end,
         %% abs/lang/abslang.abs:928--928
        true
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method releaseInstance and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% abs/lang/abslang.abs:931
 %% abs/lang/abslang.abs:931
'm_shutdownInstance'(O=#object{class=class_ABS_DC_CloudProvider=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_instance_0,Stack)->
    put(vars, #{ 'this' => O,
 'instance' => V_instance_0 }),
    try
         %% abs/lang/abslang.abs:932--932
        T_1 = future:start(maps:get('instance', get(vars)),'m_shutdown',[[]],#process_info{method= <<"shutdown"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack]),
        T_1,
         %% abs/lang/abslang.abs:933--933
        true
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method shutdownInstance and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% abs/lang/abslang.abs:936
 %% abs/lang/abslang.abs:936
'm_internalShutdownInstance'(O=#object{class=class_ABS_DC_CloudProvider=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_instance_0,Stack)->
    put(vars, #{ 'this' => O,
 'instance' => V_instance_0 }),
    try
         %% abs/lang/abslang.abs:937--937
        put(vars, (get(vars))#{'stupidTypeSystem' => maps:get('instance', get(vars))}),
         %% abs/lang/abslang.abs:940--940
        set(O,'acquiredInstances',m_ABS_StdLib_funs:f_remove(Cog,get(O,'acquiredInstances'),maps:get('stupidTypeSystem', get(vars)),[O,DC| Stack])),
         %% abs/lang/abslang.abs:943--943
        set(O,'killedInstances',m_ABS_StdLib_funs:f_insertElement(Cog,get(O,'killedInstances'),maps:get('stupidTypeSystem', get(vars)),[O,DC| Stack])),
         %% abs/lang/abslang.abs:944--944
        put(vars, (get(vars))#{'tmp1046956206' => future:start(maps:get('instance', get(vars)),'m_getShutdownDuration',[[]],#process_info{method= <<"getShutdownDuration"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack])}),
         %% abs/lang/abslang.abs:944--944
        future:await(maps:get('tmp1046956206', get(vars)), Cog, [O,DC| Stack]),
        ok,
         %% abs/lang/abslang.abs:944--944
        put(vars, (get(vars))#{'shutdown_duration' => future:get_blocking(maps:get('tmp1046956206', get(vars)), Cog, [O,DC| Stack])}),
         %% abs/lang/abslang.abs:945--945
        task:await_duration(Cog,maps:get('shutdown_duration', get(vars)),maps:get('shutdown_duration', get(vars)),[O,DC| Stack]),
        ok,
         %% abs/lang/abslang.abs:949--949
        set(O,'launchedInstances',m_ABS_StdLib_funs:f_remove(Cog,get(O,'launchedInstances'),maps:get('stupidTypeSystem', get(vars)),[O,DC| Stack])),
         %% abs/lang/abslang.abs:951--951
        put(vars, (get(vars))#{'tmp1859227008' => future:start(maps:get('instance', get(vars)),'m_getAccumulatedCost',[[]],#process_info{method= <<"getAccumulatedCost"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack])}),
         %% abs/lang/abslang.abs:951--951
        future:await(maps:get('tmp1859227008', get(vars)), Cog, [O,DC| Stack]),
        ok,
         %% abs/lang/abslang.abs:951--951
        put(vars, (get(vars))#{'cost' => future:get_blocking(maps:get('tmp1859227008', get(vars)), Cog, [O,DC| Stack])}),
         %% abs/lang/abslang.abs:952--952
        set(O,'accumulatedCostOfKilledDCs',( rationals:add(get(O,'accumulatedCostOfKilledDCs'),maps:get('cost', get(vars)))) )
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method internalShutdownInstance and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% abs/lang/abslang.abs:955
 %% abs/lang/abslang.abs:955
'm_getAccumulatedCost'(O=#object{class=class_ABS_DC_CloudProvider=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
         %% abs/lang/abslang.abs:956--956
        put(vars, (get(vars))#{'result' => 0}),
         %% abs/lang/abslang.abs:957--957
        put(vars, (get(vars))#{'t' => m_ABS_StdLib_funs:f_now(Cog,[O,DC| Stack])}),
         %% abs/lang/abslang.abs:958--961
        put(vars, (get(vars))#{'tmp1415835701' => m_ABS_StdLib_funs:f_elements(Cog,get(O,'launchedInstances'),[O,DC| Stack])}),
         %% abs/lang/abslang.abs:958--961
        []=(fun Loop ([])->
            case not (m_ABS_StdLib_funs:f_isEmpty(Cog,maps:get('tmp1415835701', get(vars)),[O,DC| Stack])) of
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
                 %% abs/lang/abslang.abs:958--961
                put(vars, (get(vars))#{'dc' => m_ABS_StdLib_funs:f_head(Cog,maps:get('tmp1415835701', get(vars)),[O,DC| Stack])}),
                 %% abs/lang/abslang.abs:958--961
                put(vars, (get(vars))#{'tmp1415835701' := m_ABS_StdLib_funs:f_tail(Cog,maps:get('tmp1415835701', get(vars)),[O,DC| Stack])}),
                 %% abs/lang/abslang.abs:959--959
                put(vars, (get(vars))#{'tmp1157462948' => future:start(maps:get('dc', get(vars)),'m_getAccumulatedCost',[[]],#process_info{method= <<"getAccumulatedCost"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack])}),
                 %% abs/lang/abslang.abs:959--959
                future:await(maps:get('tmp1157462948', get(vars)), Cog, [O,DC| Stack]),
                ok,
                 %% abs/lang/abslang.abs:959--959
                put(vars, (get(vars))#{'cost' => future:get_blocking(maps:get('tmp1157462948', get(vars)), Cog, [O,DC| Stack])}),
                 %% abs/lang/abslang.abs:960--960
                put(vars, (get(vars))#{'result' := ( rationals:add(maps:get('result', get(vars)),maps:get('cost', get(vars)))) }),
            Loop([])  end end)
        ([]),
         %% abs/lang/abslang.abs:962--962
        ( rationals:add(maps:get('result', get(vars)),get(O,'accumulatedCostOfKilledDCs'))) 
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method getAccumulatedCost and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% abs/lang/abslang.abs:966
 %% abs/lang/abslang.abs:966
'm_setInstanceDescriptions'(O=#object{class=class_ABS_DC_CloudProvider=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_instanceDescriptions_0,Stack)->
    put(vars, #{ 'this' => O,
 'instanceDescriptions' => V_instanceDescriptions_0 }),
    try
         %% abs/lang/abslang.abs:967--967
        set(O,'instanceDescriptions',maps:get('instanceDescriptions', get(vars)))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method setInstanceDescriptions and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% abs/lang/abslang.abs:971
 %% abs/lang/abslang.abs:971
'm_addInstanceDescription'(O=#object{class=class_ABS_DC_CloudProvider=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_instanceDescription_0,Stack)->
    put(vars, #{ 'this' => O,
 'instanceDescription' => V_instanceDescription_0 }),
    try
         %% abs/lang/abslang.abs:972--972
        set(O,'instanceDescriptions',m_ABS_StdLib_funs:f_insert(Cog,get(O,'instanceDescriptions'),maps:get('instanceDescription', get(vars)),[O,DC| Stack]))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method addInstanceDescription and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% abs/lang/abslang.abs:976
 %% abs/lang/abslang.abs:976
'm_removeInstanceDescription'(O=#object{class=class_ABS_DC_CloudProvider=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},V_instanceDescriptionName_0,Stack)->
    put(vars, #{ 'this' => O,
 'instanceDescriptionName' => V_instanceDescriptionName_0 }),
    try
         %% abs/lang/abslang.abs:977--977
        set(O,'instanceDescriptions',m_ABS_StdLib_funs:f_removeKey(Cog,get(O,'instanceDescriptions'),maps:get('instanceDescriptionName', get(vars)),[O,DC| Stack]))
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method removeInstanceDescription and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
 %% abs/lang/abslang.abs:980
 %% abs/lang/abslang.abs:980
'm_getInstanceDescriptions'(O=#object{class=class_ABS_DC_CloudProvider=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
         %% abs/lang/abslang.abs:981--981
        get(O,'instanceDescriptions')
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method getInstanceDescriptions and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
'set'(O=#object{class=class_ABS_DC_CloudProvider=C,ref=Ref,cog=Cog},Var,Val)->
    object:set_field_value(O, Var, Val).

'get'(O=#object{class=class_ABS_DC_CloudProvider=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Var)->
    object:get_field_value(O,Var).

-record(state,{'name'=null,'instanceDescriptions'=null,'launchedInstances'=null,'acquiredInstances'=null,'killedInstances'=null,'nextInstanceId'=null,'accumulatedCostOfKilledDCs'=null}).
'init_internal'()->
    #state{}.

 %% abs/lang/abslang.abs:841
'get_val_internal'(#state{'name'=G},'name')->
    G;
 %% abs/lang/abslang.abs:845
'get_val_internal'(#state{'instanceDescriptions'=G},'instanceDescriptions')->
    G;
 %% abs/lang/abslang.abs:848
'get_val_internal'(#state{'launchedInstances'=G},'launchedInstances')->
    G;
 %% abs/lang/abslang.abs:850
'get_val_internal'(#state{'acquiredInstances'=G},'acquiredInstances')->
    G;
 %% abs/lang/abslang.abs:851
'get_val_internal'(#state{'killedInstances'=G},'killedInstances')->
    G;
 %% abs/lang/abslang.abs:852
'get_val_internal'(#state{'nextInstanceId'=G},'nextInstanceId')->
    G;
 %% abs/lang/abslang.abs:853
'get_val_internal'(#state{'accumulatedCostOfKilledDCs'=G},'accumulatedCostOfKilledDCs')->
    G;
'get_val_internal'(_,_)->
    %% Invalid return value; handled by HTTP API when querying for non-existant field.
    %% Will never occur in generated code.
    none.

 %% abs/lang/abslang.abs:841
'set_val_internal'(S,'name',V)->
    S#state{'name'=V};
 %% abs/lang/abslang.abs:845
'set_val_internal'(S,'instanceDescriptions',V)->
    S#state{'instanceDescriptions'=V};
 %% abs/lang/abslang.abs:848
'set_val_internal'(S,'launchedInstances',V)->
    S#state{'launchedInstances'=V};
 %% abs/lang/abslang.abs:850
'set_val_internal'(S,'acquiredInstances',V)->
    S#state{'acquiredInstances'=V};
 %% abs/lang/abslang.abs:851
'set_val_internal'(S,'killedInstances',V)->
    S#state{'killedInstances'=V};
 %% abs/lang/abslang.abs:852
'set_val_internal'(S,'nextInstanceId',V)->
    S#state{'nextInstanceId'=V};
 %% abs/lang/abslang.abs:853
'set_val_internal'(S,'accumulatedCostOfKilledDCs',V)->
    S#state{'accumulatedCostOfKilledDCs'=V}.

'get_state_for_modelapi'(S)->
    [
        { 'name', S#state.'name' }
        , { 'instanceDescriptions', S#state.'instanceDescriptions' }
        , { 'launchedInstances', S#state.'launchedInstances' }
        , { 'acquiredInstances', S#state.'acquiredInstances' }
        , { 'killedInstances', S#state.'killedInstances' }
        , { 'nextInstanceId', S#state.'nextInstanceId' }
        , { 'accumulatedCostOfKilledDCs', S#state.'accumulatedCostOfKilledDCs' }
    ].
