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
The system comes with sample data:
- 3 pre-loaded customers (IDs: 1, 2, 3)
- 5 pre-loaded products (IDs: 101-105)

### Creating a Bill
1. Go to Main Menu → Billing → Create New Bill
2. Enter Customer ID (e.g., 1 for John Doe)
3. Enter Product ID (e.g., 101 for Laptop)
4. Enter quantity
5. Choose to add more items or complete the bill
6. Invoice will be generated and saved

### Adding New Customers
1. Main Menu → Customer Management → Add New Customer
2. Enter customer details (name, phone, email)
3. Customer ID is auto-generated

### Managing Products
1. Main Menu → Product Management
2. Add products, view inventory, or update stock levels

### Viewing Bills
All bills are saved to `bills.txt` and can be viewed through the Billing menu.

## Sample Data

### Customers:
- ID 1: John Doe (555-0101)
- ID 2: Jane Smith (555-0102)
- ID 3: Bob Johnson (555-0103)

### Products:
- ID 101: Laptop ($899.99, Stock: 15)
- ID 102: Mouse ($25.50, Stock: 50)
- ID 103: Keyboard ($75.00, Stock: 30)
- ID 104: Monitor ($299.99, Stock: 20)
- ID 105: USB Cable ($12.99, Stock: 100)

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
