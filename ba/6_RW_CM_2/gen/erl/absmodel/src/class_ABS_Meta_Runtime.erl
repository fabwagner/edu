-module(class_ABS_Meta_Runtime).
-include_lib("../include/abs_types.hrl").
-export([get_val_internal/2,set_val_internal/3,init_internal/0,get_state_for_modelapi/1]).
-compile(export_all).

exported() -> #{  }.

'init'(O=#object{class=class_ABS_Meta_Runtime=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},[Stack])->
    put(vars, #{}),
    O.
 %% abs/lang/abslang.abs:1237
 %% abs/lang/abslang.abs:1237
'm_getProductLine'(O=#object{class=class_ABS_Meta_Runtime=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Stack)->
    put(vars, #{ 'this' => O }),
    try
         %% abs/lang/abslang.abs:1237--1237
        builtin:getProductLine(Cog)
    catch
        _:Exception ->
            io:format(standard_error, "Uncaught ~s in method getProductLine and no recovery block in class definition, killing object ~s~n", [builtin:toString(Cog, Exception), builtin:toString(Cog, O)]),
            object:die(O, Exception), exit(Exception)
    end.
'set'(O=#object{class=class_ABS_Meta_Runtime=C,ref=Ref,cog=Cog},Var,Val)->
    object:set_field_value(O, Var, Val).

'get'(O=#object{class=class_ABS_Meta_Runtime=C,ref=Ref,cog=Cog=#cog{ref=CogRef,dc=DC}},Var)->
    object:get_field_value(O,Var).

-record(state,{}).
'init_internal'()->
    #state{}.

'get_val_internal'(_,_)->
    %% Invalid return value; handled by HTTP API when querying for non-existant field.
    %% Will never occur in generated code.
    none.

'set_val_internal'(S,S,S)->
    throw(badarg).
'get_state_for_modelapi'(S)->
    [
    ].
