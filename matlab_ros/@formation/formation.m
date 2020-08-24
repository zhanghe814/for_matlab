classdef formation < handle
    %编队文件——byzhanghe0824
    %   此处显示详细说明
    
    properties
        Ppos_now  %当前位置姿态等信息
        Ppos_des  %当前位置姿态等信息
        Ppar  %控制参数
        
    end
    
    methods
        function obj = formation(inputArg1,inputArg2)
            %UNTITLED 构造此类的实例
            %   此处显示详细说明
            obj.Property1 = inputArg1 + inputArg2;
        end
        
        function outputArg = method1(obj,inputArg)
            %METHOD1 此处显示有关此方法的摘要
            %   此处显示详细说明
            outputArg = obj.Property1 + inputArg;
        end
    end
end

