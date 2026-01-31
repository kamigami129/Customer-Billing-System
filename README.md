# Customer Billing System - C Programming

A comprehensive command-line billing system built in C for managing customers, products, inventory, and generating invoices with Nepali Rupee pricing.

## Features

### Customer Management
- Register new customers with phone number
- View registered customers
- Remove customer records

### Product Management
- Add new products with pricing (in Nepali Rupees)
- View all products with pricing and stock levels
- Edit product prices and stock quantities

### Billing & Transactions
- Create invoices with multiple items
- Automatic stock deduction during checkout
- 5% discount for registered customers
- VAT calculation (13%)
- Transaction history tracking
- Professional invoice generation

## Compilation

### Windows (MinGW):
```bash
gcc init_products.c -o output/init_products.exe
output/init_products.exe
gcc main.c -o output/main.exe
output/main.exe
```

### Linux/Mac:
```bash
gcc init_products.c -o init_products
./init_products
gcc main.c -o main
./main
```

## Usage Guide

### Initial Setup
First, run the initialization program to populate the database with products:
```bash
./init_products
```

Then launch the main system:
```bash
./main
```

### Main Menu Options
1. **User Login** - Admin access (username: admin, password: pass123)
2. **Customer Login** - Customer shopping experience
3. **Save & Exit** - Save data and close program

### Admin Functions
- Add new products
- Edit existing product prices and stock
- View transaction history
- Register new customers
- Remove customers
- View all products

### Customer Shopping
1. Enter phone number (or register as guest)
2. Browse available products
3. Add items to cart
4. View cart contents
5. Proceed to checkout
6. Bill is generated with automatic discount (if registered) and VAT

## Default Products (20 items)

### Groceries & Food Items
- Whole Wheat Bread - Rs. 389/-
- Organic Milk (1L) - Rs. 584/-
- Chicken Breast (1kg) - Rs. 1,169/-
- Eggs (Dozen) - Rs. 519/-
- Rice (2kg) - Rs. 779/-
- Olive Oil (500ml) - Rs. 1,299/-

### Beverages
- Orange Juice (1L) - Rs. 454/-
- Coffee Beans (500g) - Rs. 1,559/-
- Bottled Water (24 pack) - Rs. 649/-

### Dairy & Condiments
- Cheddar Cheese (500g) - Rs. 909/-
- Yogurt (500g) - Rs. 454/-
- Tomato Ketchup (500ml) - Rs. 389/-

### Electronics & Home Goods
- LED Bulb (10W) - Rs. 1,039/-
- Phone Charger - Rs. 1,949/-
- USB-C Cable (2m) - Rs. 1,299/-
- Kitchen Sponge (Pack of 3) - Rs. 324/-
- Aluminum Foil (50m) - Rs. 584/-

### Personal Care
- Toothpaste (100g) - Rs. 519/-
- Shampoo (200ml) - Rs. 779/-
- Hand Soap (250ml) - Rs. 389/-

## File Structure

```
main.c                - Main billing system
init_products.c       - Database initialization program
billing_data.dat      - Binary data file (customers, products, transactions)
output/
  ├── main.exe        - Main executable
  └── init_products.exe - Initialization executable
```

## Technical Details

- **Language**: C
- **Max Customers**: 100
- **Max Products**: 100
- **Max Transactions**: 200
- **Max Cart Items**: 50
- **Tax Rate**: 13% VAT
- **Registered Customer Discount**: 5%
- **Currency**: Nepali Rupees (Rs. /-)


## System Requirements

- C compiler (GCC, MinGW, MSVC, or Clang)
- Standard C libraries (stdio.h, stdlib.h, string.h, time.h)
- Console/Terminal

## Features in Detail

### Invoice Format
- Professional layout with borders
- Bill ID and date
- Customer information
- Itemized list with quantities and prices
- Subtotal, tax, and total calculations

### Stock Management
- Automatic inventory updates when bills are created
- Stock validation before purchase
- Manual stock adjustment options

### Data Persistence
- Bill history saved to text file
- In-memory storage for customers and products
- (Can be extended to file-based storage)

## Future Enhancements

Possible additions:
- File-based storage for customers and products
- Edit/delete functionality
- Customer purchase history
- Sales reports and analytics
- Discount management
- Multiple tax rates
- Payment tracking

## License

Free to use and modify for educational and commercial purposes.