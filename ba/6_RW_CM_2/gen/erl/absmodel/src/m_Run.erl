-module(m_Run).
-behaviour(application).
-include_lib("../include/abs_types.hrl").
-export([main/1]).
%% Application callbacks
-export([start/2, stop/1]).

'main'(Cog=#cog{ref=CogRef})->
    put(vars, #{}),
    O = void,
    %% FIXME: thisDC() won't work in main block (DC should be in Cog state)
    DC = object:new(cog:start(),class_ABS_DC_DeploymentComponent, [<<"Initial DC">>,dataEmptyMap,[]],Cog,[O]),
    cog_monitor:new_dc(DC),
    Stack = [DC],
     %% src/Run.abs:10--10
    put(vars, (get(vars))#{'s1' => object:new(cog:start(DC),class_Station_StationImpl,[1,3,<<"s1"/utf8>>,[]],Cog,[O,DC| Stack])}),
     %% src/Run.abs:11--11
    put(vars, (get(vars))#{'s2' => object:new(cog:start(DC),class_Station_StationImpl,[2,3,<<"s2"/utf8>>,[]],Cog,[O,DC| Stack])}),
     %% src/Run.abs:12--12
    put(vars, (get(vars))#{'s3' => object:new(cog:start(DC),class_Station_StationImpl,[3,3,<<"s3"/utf8>>,[]],Cog,[O,DC| Stack])}),
     %% src/Run.abs:14--14
    put(vars, (get(vars))#{'tr1' => object:new(cog:start(DC),class_Train_TrainImpl,[1,[]],Cog,[O,DC| Stack])}),
     %% src/Run.abs:18--18
    put(vars, (get(vars))#{'t1' => object:new(cog:start(DC),class_TrackElement_TrackElementFreeWay,[<<"t1"/utf8>>,[]],Cog,[O,DC| Stack])}),
     %% src/Run.abs:19--19
    put(vars, (get(vars))#{'t2' => object:new(cog:start(DC),class_TrackElement_TrackElementFreeWay,[<<"t2"/utf8>>,[]],Cog,[O,DC| Stack])}),
     %% src/Run.abs:20--20
    put(vars, (get(vars))#{'t3' => object:new(cog:start(DC),class_TrackElement_TrackElementFreeWay,[<<"t3"/utf8>>,[]],Cog,[O,DC| Stack])}),
     %% src/Run.abs:21--21
    put(vars, (get(vars))#{'t4' => object:new(cog:start(DC),class_TrackElement_TrackElementFreeWay,[<<"t4"/utf8>>,[]],Cog,[O,DC| Stack])}),
     %% src/Run.abs:22--22
    put(vars, (get(vars))#{'t5' => object:new(cog:start(DC),class_TrackElement_TrackElementFreeWay,[<<"t5"/utf8>>,[]],Cog,[O,DC| Stack])}),
     %% src/Run.abs:23--23
    put(vars, (get(vars))#{'t6' => object:new(cog:start(DC),class_TrackElement_TrackElementFreeWay,[<<"t6"/utf8>>,[]],Cog,[O,DC| Stack])}),
     %% src/Run.abs:24--24
    put(vars, (get(vars))#{'t7' => object:new(cog:start(DC),class_TrackElement_TrackElementFreeWay,[<<"t7"/utf8>>,[]],Cog,[O,DC| Stack])}),
     %% src/Run.abs:25--25
    put(vars, (get(vars))#{'t8' => object:new(cog:start(DC),class_TrackElement_TrackElementFreeWay,[<<"t8"/utf8>>,[]],Cog,[O,DC| Stack])}),
     %% src/Run.abs:30--30
    put(vars, (get(vars))#{'lot' => [maps:get('t1', get(vars)), maps:get('t5', get(vars))]}),
     %% src/Run.abs:31--31
    put(vars, (get(vars))#{'los' => [maps:get('s2', get(vars)), maps:get('s3', get(vars))]}),
     %% src/Run.abs:32--32
    put(vars, (get(vars))#{'tmp394645908' => future:start(maps:get('s1', get(vars)),'m_construct',[maps:get('lot', get(vars)),maps:get('los', get(vars)),[]],#process_info{method= <<"construct"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack])}),
     %% src/Run.abs:32--32
    future:await(maps:get('tmp394645908', get(vars)), Cog, [O,DC| Stack]),
    ok,
     %% src/Run.abs:34--34
    put(vars, (get(vars))#{'lot' := [maps:get('t4', get(vars))]}),
     %% src/Run.abs:35--35
    put(vars, (get(vars))#{'los' := [maps:get('s1', get(vars))]}),
     %% src/Run.abs:36--36
    put(vars, (get(vars))#{'tmp1985362663' => future:start(maps:get('s2', get(vars)),'m_construct',[maps:get('lot', get(vars)),maps:get('los', get(vars)),[]],#process_info{method= <<"construct"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack])}),
     %% src/Run.abs:36--36
    future:await(maps:get('tmp1985362663', get(vars)), Cog, [O,DC| Stack]),
    ok,
     %% src/Run.abs:38--38
    put(vars, (get(vars))#{'lot' := [maps:get('t8', get(vars))]}),
     %% src/Run.abs:39--39
    put(vars, (get(vars))#{'los' := [maps:get('s1', get(vars))]}),
     %% src/Run.abs:40--40
    put(vars, (get(vars))#{'tmp1978141335' => future:start(maps:get('s3', get(vars)),'m_construct',[maps:get('lot', get(vars)),maps:get('los', get(vars)),[]],#process_info{method= <<"construct"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack])}),
     %% src/Run.abs:40--40
    future:await(maps:get('tmp1978141335', get(vars)), Cog, [O,DC| Stack]),
    ok,
     %% src/Run.abs:42--42
    put(vars, (get(vars))#{'los' := []}),
     %% src/Run.abs:43--43
    put(vars, (get(vars))#{'lot' := [maps:get('s1', get(vars)), maps:get('t2', get(vars))]}),
     %% src/Run.abs:44--44
    put(vars, (get(vars))#{'tmp1746061516' => future:start(maps:get('t1', get(vars)),'m_construct',[maps:get('lot', get(vars)),maps:get('los', get(vars)),[]],#process_info{method= <<"construct"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack])}),
     %% src/Run.abs:44--44
    future:await(maps:get('tmp1746061516', get(vars)), Cog, [O,DC| Stack]),
    ok,
     %% src/Run.abs:46--46
    put(vars, (get(vars))#{'lot' := [maps:get('t1', get(vars)), maps:get('t3', get(vars))]}),
     %% src/Run.abs:47--47
    put(vars, (get(vars))#{'tmp2039783633' => future:start(maps:get('t2', get(vars)),'m_construct',[maps:get('lot', get(vars)),maps:get('los', get(vars)),[]],#process_info{method= <<"construct"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack])}),
     %% src/Run.abs:47--47
    future:await(maps:get('tmp2039783633', get(vars)), Cog, [O,DC| Stack]),
    ok,
     %% src/Run.abs:49--49
    put(vars, (get(vars))#{'lot' := [maps:get('t2', get(vars)), maps:get('t4', get(vars))]}),
     %% src/Run.abs:50--50
    put(vars, (get(vars))#{'tmp1094167216' => future:start(maps:get('t3', get(vars)),'m_construct',[maps:get('lot', get(vars)),maps:get('los', get(vars)),[]],#process_info{method= <<"construct"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack])}),
     %% src/Run.abs:50--50
    future:await(maps:get('tmp1094167216', get(vars)), Cog, [O,DC| Stack]),
    ok,
     %% src/Run.abs:52--52
    put(vars, (get(vars))#{'lot' := [maps:get('t3', get(vars)), maps:get('s2', get(vars))]}),
     %% src/Run.abs:53--53
    put(vars, (get(vars))#{'tmp1538844412' => future:start(maps:get('t4', get(vars)),'m_construct',[maps:get('lot', get(vars)),maps:get('los', get(vars)),[]],#process_info{method= <<"construct"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack])}),
     %% src/Run.abs:53--53
    future:await(maps:get('tmp1538844412', get(vars)), Cog, [O,DC| Stack]),
    ok,
     %% src/Run.abs:55--55
    put(vars, (get(vars))#{'lot' := [maps:get('s1', get(vars)), maps:get('t6', get(vars))]}),
     %% src/Run.abs:56--56
    put(vars, (get(vars))#{'tmp1751972013' => future:start(maps:get('t5', get(vars)),'m_construct',[maps:get('lot', get(vars)),maps:get('los', get(vars)),[]],#process_info{method= <<"construct"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack])}),
     %% src/Run.abs:56--56
    future:await(maps:get('tmp1751972013', get(vars)), Cog, [O,DC| Stack]),
    ok,
     %% src/Run.abs:58--58
    put(vars, (get(vars))#{'lot' := [maps:get('t5', get(vars)), maps:get('t7', get(vars))]}),
     %% src/Run.abs:59--59
    put(vars, (get(vars))#{'tmp1531506932' => future:start(maps:get('t6', get(vars)),'m_construct',[maps:get('lot', get(vars)),maps:get('los', get(vars)),[]],#process_info{method= <<"construct"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack])}),
     %% src/Run.abs:59--59
    future:await(maps:get('tmp1531506932', get(vars)), Cog, [O,DC| Stack]),
    ok,
     %% src/Run.abs:61--61
    put(vars, (get(vars))#{'lot' := [maps:get('t6', get(vars)), maps:get('t8', get(vars))]}),
     %% src/Run.abs:62--62
    put(vars, (get(vars))#{'tmp669812564' => future:start(maps:get('t7', get(vars)),'m_construct',[maps:get('lot', get(vars)),maps:get('los', get(vars)),[]],#process_info{method= <<"construct"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack])}),
     %% src/Run.abs:62--62
    future:await(maps:get('tmp669812564', get(vars)), Cog, [O,DC| Stack]),
    ok,
     %% src/Run.abs:64--64
    put(vars, (get(vars))#{'lot' := [maps:get('t7', get(vars)), maps:get('s3', get(vars))]}),
     %% src/Run.abs:65--65
    put(vars, (get(vars))#{'tmp560734926' => future:start(maps:get('t8', get(vars)),'m_construct',[maps:get('lot', get(vars)),maps:get('los', get(vars)),[]],#process_info{method= <<"construct"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack])}),
     %% src/Run.abs:65--65
    future:await(maps:get('tmp560734926', get(vars)), Cog, [O,DC| Stack]),
    ok,
     %% src/Run.abs:72--72
    put(vars, (get(vars))#{'reqStation1' => future:start(maps:get('tr1', get(vars)),'m_registerInStation',[maps:get('s1', get(vars)),[]],#process_info{method= <<"registerInStation"/utf8>>, creation={dataTime,builtin:currentms(Cog)}, proc_deadline=dataInfDuration},Cog,[O,DC| Stack])}),
     %% src/Run.abs:76--76
    future:await(maps:get('reqStation1', get(vars)), Cog, [O,DC| Stack]),
    ok,
     %% src/Run.abs:84--84
    T_1 = (fun() -> case maps:get('tr1', get(vars)) of
        null -> throw(dataNullPointerException);
        #object{ref=ObjRef,class=T,cog=Cog} ->
            case is_process_alive(ObjRef) of
                true ->
                    Vars=get(vars),
                    Result=T:'m_start'(maps:get('tr1', get(vars)),[O,DC| Stack]),
                    put(vars, Vars),
                    Result;
                false -> throw(dataObjectDeadException)
            end;
        _ ->
            TempFuture = future:start(maps:get('tr1', get(vars)),'m_start',[[]],#process_info{method= <<"start"/utf8>>},Cog,[O,DC| Stack]),
            future:get_blocking(TempFuture, Cog, [O,DC| Stack])
    end end)(),
    T_1.

%% ===================================================================
%% Application callbacks
%% ===================================================================

start(_StartType, _StartArgs) ->
    runtime:start_link([m_Run]).

stop(_State) ->
    ok.
