# AddressPickerView

![icon](https://raw.githubusercontent.com/JonHory/AddressPickerView/master/a1.png)

### [Swift版本传送门](https://github.com/Jonhory/AddressPickerViewForSwift)

## Contents
* Getting Started
    * [如何使用](#如何使用)
* API
    * [address.txt](#address.txt)
    * [AddressPickerView.h](#AddressPickerView.h)
* Examples
    * [Reference[参考]](#参考)


## <a id="如何使用"></a>如何使用
* 手动导入
    * 将项目中`AddressPickerView`文件夹拖入您的项目中
    * 导入主头文件即可:`#import "AddressPickerView.h"`

## <a id="address.txt"></a>address.txt
* 该文件是存放省市区的数据源

## <a id="AddressPickerView.h"></a>AddressPickerView.h
    @protocol AddressPickerViewDelegate <NSObject>

    /** 取消按钮点击事件*/
    - (void)cancelBtnClick;

    /**
     *  完成按钮点击事件
     *
     *  @param province 当前选中的省份
     *  @param city     当前选中的市
     *  @param area     当前选中的区
     */
    - (void)sureBtnClickReturnProvince:(NSString *)province
                                  City:(NSString *)city
                                  Area:(NSString *)area;

    @end

    @interface AddressPickerView : UIView

    /** 实现点击按钮代理*/
    @property (nonatomic ,weak) id<AddressPickerViewDelegate> delegate;



## <a id="Province.h"></a>AddressProvince
    @interface Province : NSObject
    @property (nonatomic, strong) NSString       * name;/**< 省名字*/
    @property (nonatomic, strong) NSArray        * cities;/**< 该省包含的所有城市名称*/
    @property (nonatomic, strong) NSMutableArray * cityModels;/**< 该省包含的所有城市模型*/


    /**
     *  初始化省份
     *
     *  @param name   省名字
     *  @param cities 省包含的所有城市名字
     *
     *  @return 初始化省份
     */
    - (instancetype)initWithName:(NSString *)name
                          cities:(NSArray *)cities;

    /**
     *  初始化省份
     *
     *  @param name   省名字
     *  @param cities 省包含的所有城市名字
     *
     *  @return 初始化省份
     */
    + (instancetype)provinceWithName:(NSString *)name
                              cities:(NSArray *)cities;

## <a id="City.h"></a>AddressCity
    @property (nonatomic ,strong) NSString * cityName;/**< 城市名*/

    @property (nonatomic ,strong) NSArray  * areas;/**< 城市包含的所有地区*/


    /**
     *  初始化城市
     *
     *  @param name  城市名字
     *  @param areas 城市包含的地区
     *
     *  @return 初始化城市
     */
    - (instancetype)initWithName:(NSString *)name
                           areas:(NSArray *)areas;

    /**
     *  初始化城市
     *
     *  @param cityName 城市名字
     *  @param areas    城市包含的地区
     *
     *  @return 初始化城市
     */
    + (instancetype)cityWithName:(NSString *)cityName
                           areas:(NSArray *)areas;


## <a id="参考"></a>使用参考

    @property (nonatomic ,strong) AddressPickerView * pickerView;
    
    - (void)viewDidLoad {
        [super viewDidLoad];

        self.view.backgroundColor = [UIColor lightGrayColor];
    
        [self.view addSubview:self.pickerView];
    }
    
    - (AddressPickerView *)pickerView{
        if (!_pickerView) {
            _pickerView = [[AddressPickerView alloc]initWithFrame:CGRectMake(0, SCREEN.height , SCREEN.width, 215)];
            _pickerView.delegate = self;
        }
        return _pickerView;
    }


## <a id="关于我"></a>关于我
 * 如果在使用过程中遇到问题，或者想要与我分享<jonhory@163.com>