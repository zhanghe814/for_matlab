classdef formation < handle
    %����ļ�����byzhanghe0824
    %   �˴���ʾ��ϸ˵��
    
    properties
        Ppos_now  %��ǰλ����̬����Ϣ
        Ppos_des  %��ǰλ����̬����Ϣ
        Ppar  %���Ʋ���
        
    end
    
    methods
        function obj = formation(inputArg1,inputArg2)
            %UNTITLED ��������ʵ��
            %   �˴���ʾ��ϸ˵��
            obj.Property1 = inputArg1 + inputArg2;
        end
        
        function outputArg = method1(obj,inputArg)
            %METHOD1 �˴���ʾ�йش˷�����ժҪ
            %   �˴���ʾ��ϸ˵��
            outputArg = obj.Property1 + inputArg;
        end
    end
end

